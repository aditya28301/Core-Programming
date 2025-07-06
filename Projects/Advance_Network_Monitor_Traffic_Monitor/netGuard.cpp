#include <condition_variable>
#include <set>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <csignal>
#include <cstring>
#include <queue>

// Linux-specific headers
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <ifaddrs.h>

#define MAX_EVENTS 64
#define BUFFER_SIZE 65536
#define MAX_THREADS 8

struct PacketStats {
    std::atomic<uint64_t> total_packets{0};
    std::atomic<uint64_t> tcp_packets{0};
    std::atomic<uint64_t> udp_packets{0};
    std::atomic<uint64_t> icmp_packets{0};
    std::atomic<uint64_t> total_bytes{0};
    std::atomic<uint64_t> suspicious_activity{0};
};

struct ConnectionInfo {
    std::string src_ip;
    std::string dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t protocol;
    uint64_t packet_count;
    uint64_t byte_count;
    std::chrono::steady_clock::time_point last_seen;
};

class NetworkMonitor {
private:
    int raw_socket;
    bool running;
    int epoll_fd;
    std::vector<std::thread> worker_threads;
    std::queue<std::vector<uint8_t>> packet_queue;
    std::mutex queue_mutex;
    std::condition_variable queue_cv;
    
    PacketStats stats;
    std::unordered_map<std::string, ConnectionInfo> connections;
    std::mutex connections_mutex;
    
    // Thread pool for packet processing
    std::vector<std::thread> processing_threads;
    std::atomic<bool> shutdown_flag{false};

public:
    NetworkMonitor() :  raw_socket(-1), running(false), epoll_fd(-1){
        setup_signal_handlers();
    }
    
    ~NetworkMonitor() {
        stop();
        cleanup();
    }
    
    bool initialize() {
        // Create raw socket for packet capture
        raw_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
        if (raw_socket < 0) {
            perror("Failed to create raw socket");
            std::cerr << "Note: Run with sudo for raw socket access\n";
            return false;
        }
        
        // Create epoll instance for high-performance I/O multiplexing
        epoll_fd = epoll_create1(EPOLL_CLOEXEC);
        if (epoll_fd < 0) {
            perror("Failed to create epoll instance");
            return false;
        }
        
        // Add raw socket to epoll
        struct epoll_event ev;
        ev.events = EPOLLIN | EPOLLET; // Edge-triggered for high performance
        ev.data.fd = raw_socket;
        
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, raw_socket, &ev) < 0) {
            perror("Failed to add socket to epoll");
            return false;
        }
        
        // Set socket to non-blocking mode
        int flags = fcntl(raw_socket, F_GETFL, 0);
        fcntl(raw_socket, F_SETFL, flags | O_NONBLOCK);
        
        std::cout << "✓ Network monitor initialized successfully\n";
        std::cout << "✓ Raw socket created (fd: " << raw_socket << ")\n";
        std::cout << "✓ Epoll instance ready (fd: " << epoll_fd << ")\n";
        
        return true;
    }
    
    void start() {
        if (running) return;
        
        running = true;
        shutdown_flag = false;
        
        // Start packet processing threads
        for (int i = 0; i < MAX_THREADS; ++i) {
            processing_threads.emplace_back(&NetworkMonitor::packet_processor, this);
        }
        
        // Start network capture thread
        worker_threads.emplace_back(&NetworkMonitor::capture_packets, this);
        
        // Start statistics display thread
        worker_threads.emplace_back(&NetworkMonitor::display_stats, this);
        
        // Start connection monitor thread
        worker_threads.emplace_back(&NetworkMonitor::monitor_connections, this);
        
        std::cout << "🚀 NetGuard monitoring started with " << MAX_THREADS << " processing threads\n";
        std::cout << "📊 Real-time statistics will be displayed every 5 seconds\n";
        std::cout << "🔍 Monitoring all network interfaces for suspicious activity\n\n";
    }
    
    void stop() {
        if (!running) return;
        
        running = false;
        shutdown_flag = true;
        queue_cv.notify_all();
        
        // Join all threads
        for (auto& t : worker_threads) {
            if (t.joinable()) t.join();
        }
        
        for (auto& t : processing_threads) {
            if (t.joinable()) t.join();
        }
        
        std::cout << "\n🛑 NetGuard monitoring stopped\n";
    }

private:
    void capture_packets() {
        struct epoll_event events[MAX_EVENTS];
        uint8_t buffer[BUFFER_SIZE];
        
        while (running) {
            int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, 1000);
            
            if (nfds < 0) {
                if (errno != EINTR) {
                    perror("epoll_wait error");
                }
                continue;
            }
            
            for (int i = 0; i < nfds; ++i) {
                if (events[i].data.fd == raw_socket) {
                    // Read packets in a tight loop for maximum performance
                    while (true) {
                        ssize_t packet_size = recv(raw_socket, buffer, BUFFER_SIZE, MSG_DONTWAIT);
                        if (packet_size <= 0) {
                            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                                perror("recv error");
                            }
                            break;
                        }
                        
                        // Queue packet for processing
                        std::vector<uint8_t> packet(buffer, buffer + packet_size);
                        {
                            std::lock_guard<std::mutex> lock(queue_mutex);
                            packet_queue.push(std::move(packet));
                        }
                        queue_cv.notify_one();
                        
                        stats.total_packets++;
                        stats.total_bytes += packet_size;
                    }
                }
            }
        }
    }
    
    void packet_processor() {
        while (!shutdown_flag) {
            std::vector<uint8_t> packet;
            
            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                queue_cv.wait(lock, [this] { return !packet_queue.empty() || shutdown_flag; });
                
                if (shutdown_flag) break;
                
                packet = std::move(packet_queue.front());
                packet_queue.pop();
            }
            
            process_packet(packet);
        }
    }
    
    void process_packet(const std::vector<uint8_t>& packet) {
        if (packet.size() < sizeof(struct ethhdr)) return;
        
        const struct ethhdr* eth_header = reinterpret_cast<const struct ethhdr*>(packet.data());
        
        // Only process IP packets
        if (ntohs(eth_header->h_proto) != ETH_P_IP) return;
        
        if (packet.size() < sizeof(struct ethhdr) + sizeof(struct iphdr)) return;
        
        const struct iphdr* ip_header = reinterpret_cast<const struct iphdr*>(
            packet.data() + sizeof(struct ethhdr));
        
        // Extract IP addresses
        char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &ip_header->saddr, src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &ip_header->daddr, dst_ip, INET_ADDRSTRLEN);
        
        uint16_t src_port = 0, dst_port = 0;
        
        // Process based on protocol
        switch (ip_header->protocol) {
            case IPPROTO_TCP: {
                stats.tcp_packets++;
                if (packet.size() >= sizeof(struct ethhdr) + (ip_header->ihl * 4) + sizeof(struct tcphdr)) {
                    const struct tcphdr* tcp_header = reinterpret_cast<const struct tcphdr*>(
                        packet.data() + sizeof(struct ethhdr) + (ip_header->ihl * 4));
                    src_port = ntohs(tcp_header->th_sport);
                    dst_port = ntohs(tcp_header->th_dport);
                    
                    // Detect potential port scanning
                    if (tcp_header->th_flags & TH_SYN && !(tcp_header->th_flags & TH_ACK)) {
                        check_port_scan(src_ip, dst_port);
                    }
                }
                break;
            }
            case IPPROTO_UDP: {
                stats.udp_packets++;
                if (packet.size() >= sizeof(struct ethhdr) + (ip_header->ihl * 4) + sizeof(struct udphdr)) {
                    const struct udphdr* udp_header = reinterpret_cast<const struct udphdr*>(
                        packet.data() + sizeof(struct ethhdr) + (ip_header->ihl * 4));
                    src_port = ntohs(udp_header->uh_sport);
                    dst_port = ntohs(udp_header->uh_dport);
                }
                break;
            }
            case IPPROTO_ICMP:
                stats.icmp_packets++;
                break;
        }
        
        // Update connection tracking
        update_connection_info(src_ip, dst_ip, src_port, dst_port, ip_header->protocol, packet.size());
    }
    
    void check_port_scan(const std::string& src_ip, uint16_t dst_port) {
        static std::unordered_map<std::string, std::vector<uint16_t>> scan_attempts;
        static std::mutex scan_mutex;
        
        std::lock_guard<std::mutex> lock(scan_mutex);
        
        auto& ports = scan_attempts[src_ip];
        ports.push_back(dst_port);
        
        // Keep only recent attempts (last 100)
        if (ports.size() > 100) {
            ports.erase(ports.begin(), ports.begin() + 50);
        }
        
        // Detect if scanning multiple ports
        std::set<uint16_t> unique_ports(ports.begin(), ports.end());
        if (unique_ports.size() > 10) {
            stats.suspicious_activity++;
            std::cout << "🚨 ALERT: Potential port scan detected from " << src_ip 
                      << " (targeting " << unique_ports.size() << " different ports)\n";
        }
    }
    
    void update_connection_info(const std::string& src_ip, const std::string& dst_ip,
                               uint16_t src_port, uint16_t dst_port, uint8_t protocol, size_t packet_size) {
        std::string conn_key = src_ip + ":" + std::to_string(src_port) + "->" + 
                              dst_ip + ":" + std::to_string(dst_port) + "_" + std::to_string(protocol);
        
        std::lock_guard<std::mutex> lock(connections_mutex);
        
        auto& conn = connections[conn_key];
        conn.src_ip = src_ip;
        conn.dst_ip = dst_ip;
        conn.src_port = src_port;
        conn.dst_port = dst_port;
        conn.protocol = protocol;
        conn.packet_count++;
        conn.byte_count += packet_size;
        conn.last_seen = std::chrono::steady_clock::now();
    }
    
    void display_stats() {
        auto start_time = std::chrono::steady_clock::now();
        
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            
            auto current_time = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
            
            std::cout << "\n" << std::string(80, '=') << "\n";
            std::cout << "📊 NETGUARD STATISTICS (Runtime: " << elapsed << "s)\n";
            std::cout << std::string(80, '=') << "\n";
            
            std::cout << "📦 Total Packets: " << stats.total_packets.load() << "\n";
            std::cout << "📊 TCP: " << stats.tcp_packets.load() 
                      << " | UDP: " << stats.udp_packets.load() 
                      << " | ICMP: " << stats.icmp_packets.load() << "\n";
            std::cout << "💾 Total Bytes: " << format_bytes(stats.total_bytes.load()) << "\n";
            std::cout << "🚨 Suspicious Events: " << stats.suspicious_activity.load() << "\n";
            
            // Display top connections
            display_top_connections();
            
            if (elapsed > 0) {
                double pps = static_cast<double>(stats.total_packets.load()) / elapsed;
                double bps = static_cast<double>(stats.total_bytes.load()) / elapsed;
                std::cout << "⚡ Rate: " << std::fixed << std::setprecision(2) 
                          << pps << " pps | " << format_bytes(static_cast<uint64_t>(bps)) << "/s\n";
            }
        }
    }
    
    void display_top_connections() {
        std::lock_guard<std::mutex> lock(connections_mutex);
        
        if (connections.empty()) return;
        
        std::cout << "\n🔗 TOP ACTIVE CONNECTIONS:\n";
        std::cout << std::left << std::setw(25) << "Source" 
                  << std::setw(25) << "Destination" 
                  << std::setw(8) << "Proto" 
                  << std::setw(10) << "Packets" 
                  << std::setw(12) << "Bytes" << "\n";
        std::cout << std::string(80, '-') << "\n";
        
        // Sort connections by packet count
        std::vector<std::pair<std::string, ConnectionInfo>> sorted_conns(connections.begin(), connections.end());
        std::sort(sorted_conns.begin(), sorted_conns.end(),
                  [](const auto& a, const auto& b) { return a.second.packet_count > b.second.packet_count; });
        
        int count = 0;
        for (const auto& [key, conn] : sorted_conns) {
            if (++count > 5) break; // Show top 5
            
            std::string proto_str = (conn.protocol == IPPROTO_TCP) ? "TCP" : 
                                   (conn.protocol == IPPROTO_UDP) ? "UDP" : "OTHER";
            
            std::cout << std::left << std::setw(25) << (conn.src_ip + ":" + std::to_string(conn.src_port))
                      << std::setw(25) << (conn.dst_ip + ":" + std::to_string(conn.dst_port))
                      << std::setw(8) << proto_str
                      << std::setw(10) << conn.packet_count
                      << std::setw(12) << format_bytes(conn.byte_count) << "\n";
        }
    }
    
    void monitor_connections() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            
            auto now = std::chrono::steady_clock::now();
            std::lock_guard<std::mutex> lock(connections_mutex);
            
            // Clean up old connections (older than 5 minutes)
            auto it = connections.begin();
            while (it != connections.end()) {
                auto age = std::chrono::duration_cast<std::chrono::minutes>(now - it->second.last_seen);
                if (age.count() > 5) {
                    it = connections.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    
    std::string format_bytes(uint64_t bytes) {
        const char* units[] = {"B", "KB", "MB", "GB", "TB"};
        int unit = 0;
        double size = static_cast<double>(bytes);
        
        while (size >= 1024 && unit < 4) {
            size /= 1024;
            unit++;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << size << " " << units[unit];
        return oss.str();
    }
    
    void setup_signal_handlers() {
        signal(SIGINT, [](int) {
            std::cout << "\n🛑 Received interrupt signal, shutting down gracefully...\n";
            // Note: In a real application, you'd use a global variable or singleton
            exit(0);
        });
    }
    
    void cleanup() {
        if (raw_socket >= 0) {
            close(raw_socket);
            raw_socket = -1;
        }
        if (epoll_fd >= 0) {
            close(epoll_fd);
            epoll_fd = -1;
        }
    }
};

int main() {
    std::cout << R"(
    ███╗   ██╗███████╗████████╗ ██████╗ ██╗   ██╗ █████╗ ██████╗ ██████╗ 
    ████╗  ██║██╔════╝╚══██╔══╝██╔════╝ ██║   ██║██╔══██╗██╔══██╗██╔══██╗
    ██╔██╗ ██║█████╗     ██║   ██║  ███╗██║   ██║███████║██████╔╝██║  ██║
    ██║╚██╗██║██╔══╝     ██║   ██║   ██║██║   ██║██╔══██║██╔══██╗██║  ██║
    ██║ ╚████║███████╗   ██║   ╚██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝
    ╚═╝  ╚═══╝╚══════╝   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ 
    
    🔥 Advanced Linux Network Traffic Monitor & Security Analyzer
    ⚡ High-Performance Multi-threaded Architecture
    🚀 Built with C++, Raw Sockets, Epoll, and System Programming
    
)" << std::endl;

    // Check if running as root
    if (geteuid() != 0) {
        std::cout << "⚠️  WARNING: This application requires root privileges for raw socket access.\n";
        std::cout << "   Please run with: sudo ./netguard\n\n";
    }
    
    NetworkMonitor monitor;
    
    if (!monitor.initialize()) {
        std::cerr << "❌ Failed to initialize network monitor\n";
        return 1;
    }
    
    monitor.start();
    
    // Keep main thread alive
    std::cout << "Press Ctrl+C to stop monitoring...\n";
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
