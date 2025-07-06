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
    WorkStealingQueue(const WorkStealingQueue&) = delete;
    WorkStealingQueue& operator=(const WorkStealingQueue&) = delete;
    WorkStealingQueue(WorkStealingQueue&&) = delete;
    WorkStealingQueue& operator=(WorkStealingQueue&&) = delete;

    void push(std::function<void()> task);
    bool try_pop(std::function<void()>& task);
    bool try_steal(std::function<void()>& task);
    bool empty() const;
    size_t size() const;
};

struct ThreadPoolConfig {
    size_t min_threads = 1;
    size_t max_threads = std::thread::hardware_concurrency();
    std::chrono::milliseconds idle_timeout{5000};
    bool enable_work_stealing = true;
    
    ThreadPoolConfig();
};

class ThreadPool {
private:
    ThreadPoolConfig config_;
    std::vector<std::unique_ptr<std::thread>> threads_;
    std::vector<std::unique_ptr<WorkStealingQueue>> local_queues_;
    std::queue<std::function<void()>> global_queue_;
    mutable std::mutex global_queue_mutex_;
    std::condition_variable condition_;
    std::atomic<bool> shutdown_{false};
    std::atomic<size_t> active_threads_{0};
    std::atomic<size_t> pending_tasks_{0};
    static thread_local std::mt19937 rng_;

    void worker_thread(size_t thread_id);
    bool try_steal_task(std::function<void()>& task, size_t exclude_thread);
    bool try_pop_global_task(std::function<void()>& task);
    void add_thread();
    WorkStealingQueue* get_local_queue();
    size_t get_thread_id();

public:
    explicit ThreadPool(const ThreadPoolConfig& config = ThreadPoolConfig{});
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;

    template<typename F, typename... Args>
    auto submit(F&& f, Args&&... args) -> std::future<typename std::invoke_result_t<F, Args...>> {
        using return_type = typename std::invoke_result_t<F, Args...>;
        
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
        std::future<return_type> result = task->get_future();
        auto wrapper = [task]() { (*task)(); };
        
        {
            std::lock_guard<std::mutex> lock(global_queue_mutex_);
            global_queue_.emplace(std::move(wrapper));
        }
        condition_.notify_one();
        pending_tasks_.fetch_add(1);
        return result;
    }

    template<typename F, typename... Args>
    void post(F&& f, Args&&... args) {
        auto wrapper = [f = std::forward<F>(f), args...]() mutable {
            f(args...);
        };
        
        {
            std::lock_guard<std::mutex> lock(global_queue_mutex_);
            global_queue_.emplace(std::move(wrapper));
        }
        condition_.notify_one();
        pending_tasks_.fetch_add(1);
    }

    size_t thread_count() const;
    size_t pending_task_count() const;
    bool is_idle() const;
    void wait_for_tasks();
    void shutdown();
    const ThreadPoolConfig& config() const;
};

} // namespace thread_pool
