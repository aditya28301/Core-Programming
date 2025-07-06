# Create the fixed setup script
cat > setup_thread_pool.sh << 'EOF'
#!/bin/bash

set -e
echo "🚀 Thread Pool Library - Complete Setup"
echo "========================================"

# Clean and create directories
rm -rf include src build bin Makefile CMakeLists.txt README.md
mkdir -p include src build bin

# Create header file
cat > include/thread_pool.hpp << 'HEADER_EOF'
#pragma once
#include <atomic>
#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <random>
#include <thread>
#include <type_traits>
#include <vector>
#include <chrono>

namespace thread_pool {
class WorkStealingQueue {
private:
    mutable std::mutex mutex_;
    std::deque<std::function<void()>> queue_;
public:
    WorkStealingQueue() = default;
    void push(std::function<void()> task);
    bool try_pop(std::function<void()>& task);
    bool try_steal(std::function<void()>& task);
    bool empty() const;
    size_t size() const;
};

struct ThreadPoolConfig {
    size_t min_threads = 1;
    size_t max_threads = std::thread::hardware_concurrency();
    bool enable_work_stealing = true;
    ThreadPoolConfig() {
        if (max_threads == 0) max_threads = 4;
        if (min_threads > max_threads) min_threads = max_threads;
    }
};

class ThreadPool {
private:
    ThreadPoolConfig config_;
    std::vector<std::unique_ptr<std::thread>> threads_;
    std::queue<std::function<void()>> global_queue_;
    mutable std::mutex global_queue_mutex_;
    std::condition_variable condition_;
    std::atomic<bool> shutdown_{false};
    std::atomic<size_t> active_threads_{0};
    std::atomic<size_t> pending_tasks_{0};

    void worker_thread();
    bool try_pop_global_task(std::function<void()>& task);

public:
    explicit ThreadPool(const ThreadPoolConfig& config = ThreadPoolConfig{});
    ~ThreadPool();

    template<typename F, typename... Args>
    auto submit(F&& f, Args&&... args) -> std::future<typename std::invoke_result_t<F, Args...>> {
        using return_type = typename std::invoke_result_t<F, Args...>;
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        std::future<return_type> result = task->get_future();
        {
            std::lock_guard<std::mutex> lock(global_queue_mutex_);
            global_queue_.emplace([task]() { (*task)(); });
        }
        condition_.notify_one();
        pending_tasks_.fetch_add(1);
        return result;
    }

    size_t thread_count() const;
    bool is_idle() const;
    void wait_for_tasks();
};
} // namespace thread_pool
HEADER_EOF

# Create implementation file
cat > src/thread_pool.cpp << 'IMPL_EOF'
#include "thread_pool.hpp"

namespace thread_pool {

void WorkStealingQueue::push(std::function<void()> task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push_front(std::move(task));
}

bool WorkStealingQueue::try_pop(std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty()) return false;
    task = std::move(queue_.front());
    queue_.pop_front();
    return true;
}

bool WorkStealingQueue::try_steal(std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty()) return false;
    task = std::move(queue_.back());
    queue_.pop_back();
    return true;
}

bool WorkStealingQueue::empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}

size_t WorkStealingQueue::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.size();
}

ThreadPool::ThreadPool(const ThreadPoolConfig& config) : config_(config) {
    for (size_t i = 0; i < config_.min_threads; ++i) {
        threads_.emplace_back(std::make_unique<std::thread>(&ThreadPool::worker_thread, this));
    }
}

ThreadPool::~ThreadPool() {
    shutdown_.store(true);
    condition_.notify_all();
    for (auto& thread : threads_) {
        if (thread && thread->joinable()) thread->join();
    }
}

void ThreadPool::worker_thread() {
    active_threads_.fetch_add(1);
    while (!shutdown_.load()) {
        std::function<void()> task;
        if (try_pop_global_task(task)) {
            task();
            pending_tasks_.fetch_sub(1);
        } else {
            std::unique_lock<std::mutex> lock(global_queue_mutex_);
            condition_.wait_for(lock, std::chrono::milliseconds(100), 
                [this] { return shutdown_.load() || !global_queue_.empty(); });
        }
    }
    active_threads_.fetch_sub(1);
}

bool ThreadPool::try_pop_global_task(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(global_queue_mutex_);
    if (global_queue_.empty()) return false;
    task = std::move(global_queue_.front());
    global_queue_.pop();
    return true;
}

size_t ThreadPool::thread_count() const { return active_threads_.load(); }
bool ThreadPool::is_idle() const { return pending_tasks_.load() == 0; }

void ThreadPool::wait_for_tasks() {
    while (!is_idle()) std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

} // namespace thread_pool
IMPL_EOF

# Create example file
cat > src/example.cpp << 'EXAMPLE_EOF'
#include "thread_pool.hpp"
#include <iostream>

using namespace thread_pool;

int main() {
    std::cout << "🚀 Thread Pool Library - Demo\n\n";
    
    ThreadPool pool;
    
    std::cout << "1. Basic Tasks:\n";
    auto future1 = pool.submit([]() -> int { 
        std::cout << "   Task 1: Computing 42...\n";
        return 42; 
    });
    
    auto future2 = pool.submit([](int x, int y) -> int { 
        std::cout << "   Task 2: Adding " << x << " + " << y << "\n";
        return x + y; 
    }, 10, 20);
    
    std::cout << "   Result 1: " << future1.get() << std::endl;
    std::cout << "   Result 2: " << future2.get() << std::endl;
    
    std::cout << "\n2. Multiple Tasks:\n";
    std::vector<std::future<int>> futures;
    for (int i = 0; i < 5; ++i) {
        futures.emplace_back(pool.submit([i]() -> int {
            std::cout << "   Task " << i << " executing...\n";
            return i * i;
        }));
    }
    
    std::cout << "   Results: ";
    for (auto& future : futures) {
        std::cout << future.get() << " ";
    }
    std::cout << "\n\n";
    
    std::cout << "3. Thread Pool Stats:\n";
    std::cout << "   Active threads: " << pool.thread_count() << std::endl;
    std::cout << "   Is idle: " << (pool.is_idle() ? "Yes" : "No") << std::endl;
    
    pool.wait_for_tasks();
    
    std::cout << "\n✅ All tasks completed successfully!\n";
    std::cout << "🎉 Thread Pool Library is working perfectly!\n";
    
    return 0;
}
EXAMPLE_EOF

# Create Makefile with proper tabs
printf "CXX = g++\nCXXFLAGS = -std=c++17 -pthread -O2 -Wall\nINCLUDES = -Iinclude\n\n" > Makefile
printf "all:\n" >> Makefile
printf "\tmkdir -p build bin\n" >> Makefile
printf "\t\$(CXX) \$(CXXFLAGS) \$(INCLUDES) -c src/thread_pool.cpp -o build/thread_pool.o\n" >> Makefile
printf "\t\$(CXX) \$(CXXFLAGS) \$(INCLUDES) -c src/example.cpp -o build/example.o\n" >> Makefile
printf "\t\$(CXX) build/thread_pool.o build/example.o -o bin/example \$(CXXFLAGS)\n" >> Makefile
printf "\t@echo \"✅ Build complete!\"\n\n" >> Makefile
printf "run: all\n" >> Makefile
printf "\t@echo \"🚀 Running demo...\"\n" >> Makefile
printf "\t@echo \"\"\n" >> Makefile
printf "\t@./bin/example\n\n" >> Makefile
printf "clean:\n" >> Makefile
printf "\trm -rf build bin\n\n" >> Makefile
printf ".PHONY: all run clean\n" >> Makefile

echo "✅ All files created!"
echo "📁 Files:"
ls -la include/ src/ Makefile

echo ""
echo "🔨 Building..."
make

echo ""
echo "🚀 Running demo..."
make run

echo ""
echo "🎉 SUCCESS! Use 'make run' to run again."
EOF

# Make executable and run
chmod +x setup_thread_pool.sh
./setup_thread_pool.sh
