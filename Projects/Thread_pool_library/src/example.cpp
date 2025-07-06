#include "thread_pool.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace thread_pool;

int main() {
    std::cout << "🚀 Thread Pool Library - Basic Demo\n";
    std::cout << "Hardware threads: " << std::thread::hardware_concurrency() << "\n\n";
    
    ThreadPool pool;
    
    std::cout << "1. Basic Tasks:\n";
    
    // Basic tasks
    auto future1 = pool.submit([]() -> int { 
        std::cout << "   Task 1: Calculating 42...\n";
        return 42; 
    });
    
    auto future2 = pool.submit([](int x, int y) -> int { 
        std::cout << "   Task 2: Adding " << x << " + " << y << "\n";
        return x + y; 
    }, 10, 20);
    
    std::cout << "   Result 1: " << future1.get() << std::endl;
    std::cout << "   Result 2: " << future2.get() << std::endl;
    
    std::cout << "\n2. Multiple Tasks:\n";
    
    // Multiple tasks
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
    
    std::cout << "3. Fire-and-Forget Tasks:\n";
    
    // Fire-and-forget tasks
    for (int i = 0; i < 3; ++i) {
        pool.post([i]() {
            std::cout << "   Fire-and-forget task " << i << " executed!\n";
        });
    }
    
    std::cout << "\n4. Thread Pool Stats:\n";
    std::cout << "   Active threads: " << pool.thread_count() << std::endl;
    std::cout << "   Pending tasks: " << pool.pending_task_count() << std::endl;
    std::cout << "   Is idle: " << (pool.is_idle() ? "Yes" : "No") << std::endl;
    
    // Wait for all tasks to complete
    pool.wait_for_tasks();
    
    std::cout << "\n✅ All tasks completed successfully!\n";
    std::cout << "🎉 Thread Pool Library is working perfectly!\n";
    
    return 0;
}
