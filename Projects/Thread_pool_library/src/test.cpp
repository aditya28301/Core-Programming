#include "thread_pool.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <atomic>

using namespace thread_pool;

int main() {
    std::cout << "🧪 Thread Pool Library - Test Suite\n\n";
    
    int tests_passed = 0;
    int tests_total = 0;
    
    // Test 1: Basic functionality
    {
        tests_total++;
        std::cout << "Test 1: Basic task submission... ";
        try {
            ThreadPool pool;
            auto future = pool.submit([]() -> int { return 42; });
            assert(future.get() == 42);
            std::cout << "✅ PASSED\n";
            tests_passed++;
        } catch (...) {
            std::cout << "❌ FAILED\n";
        }
    }
    
    // Test 2: Multiple tasks
    {
        tests_total++;
        std::cout << "Test 2: Multiple tasks... ";
        try {
            ThreadPool pool;
            std::vector<std::future<int>> futures;
            
            for (int i = 0; i < 10; ++i) {
                futures.emplace_back(pool.submit([i]() -> int { return i * 2; }));
            }
            
            bool all_correct = true;
            for (int i = 0; i < 10; ++i) {
                if (futures[i].get() != i * 2) {
                    all_correct = false;
                    break;
                }
            }
            
            assert(all_correct);
            std::cout << "✅ PASSED\n";
            tests_passed++;
        } catch (...) {
            std::cout << "❌ FAILED\n";
        }
    }
    
    // Test 3: Exception handling
    {
        tests_total++;
        std::cout << "Test 3: Exception handling... ";
        try {
            ThreadPool pool;
            auto future = pool.submit([]() -> int {
                throw std::runtime_error("Test exception");
                return 42;
            });
            
            bool exception_caught = false;
            try {
                future.get();
            } catch (const std::runtime_error&) {
                exception_caught = true;
            }
            
            assert(exception_caught);
            std::cout << "✅ PASSED\n";
            tests_passed++;
        } catch (...) {
            std::cout << "❌ FAILED\n";
        }
    }
    
    // Test 4: Fire-and-forget
    {
        tests_total++;
        std::cout << "Test 4: Fire-and-forget tasks... ";
        try {
            ThreadPool pool;
            std::atomic<int> counter{0};
            
            for (int i = 0; i < 20; ++i) {
                pool.post([&counter]() {
                    counter.fetch_add(1);
                });
            }
            
            pool.wait_for_tasks();
            assert(counter.load() == 20);
            std::cout << "✅ PASSED\n";
            tests_passed++;
        } catch (...) {
            std::cout << "❌ FAILED\n";
        }
    }
    
    std::cout << "\n📊 Test Results:\n";
    std::cout << "   Passed: " << tests_passed << "/" << tests_total << "\n";
    
    if (tests_passed == tests_total) {
        std::cout << "🎉 All tests passed!\n";
        return 0;
    } else {
        std::cout << "❌ Some tests failed!\n";
        return 1;
    }
}
