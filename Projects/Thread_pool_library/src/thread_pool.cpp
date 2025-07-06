#include "thread_pool.hpp"

namespace thread_pool {

thread_local std::mt19937 ThreadPool::rng_{std::random_device{}()};

void WorkStealingQueue::push(std::function<void()> task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push_front(std::move(task));
}

bool WorkStealingQueue::try_pop(std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty()) {
        return false;
    }
    task = std::move(queue_.front());
    queue_.pop_front();
    return true;
}

bool WorkStealingQueue::try_steal(std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty()) {
        return false;
    }
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

ThreadPoolConfig::ThreadPoolConfig() {
    if (max_threads == 0) {
        max_threads = 4;
    }
    if (min_threads > max_threads) {
        min_threads = max_threads;
    }
}

ThreadPool::ThreadPool(const ThreadPoolConfig& config) : config_(config) {
    for (size_t i = 0; i < config_.min_threads; ++i) {
        add_thread();
    }
}

ThreadPool::~ThreadPool() {
    shutdown();
}

void ThreadPool::worker_thread(size_t thread_id) {
    active_threads_.fetch_add(1);
    
    while (!shutdown_.load()) {
        std::function<void()> task;
        bool task_found = false;
        
        if (thread_id < local_queues_.size() && local_queues_[thread_id]->try_pop(task)) {
            task_found = true;
        } else if (config_.enable_work_stealing && try_steal_task(task, thread_id)) {
            task_found = true;
        } else if (try_pop_global_task(task)) {
            task_found = true;
        }
        
        if (task_found) {
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

bool ThreadPool::try_steal_task(std::function<void()>& task, size_t exclude_thread) {
    size_t num_threads = local_queues_.size();
    if (num_threads <= 1) return false;
    
    for (size_t i = 0; i < num_threads; ++i) {
        if (i != exclude_thread && i < local_queues_.size() &&
            local_queues_[i]->try_steal(task)) {
            return true;
        }
    }
    return false;
}

bool ThreadPool::try_pop_global_task(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(global_queue_mutex_);
    if (global_queue_.empty()) {
        return false;
    }
    task = std::move(global_queue_.front());
    global_queue_.pop();
    return true;
}

void ThreadPool::add_thread() {
    size_t thread_id = threads_.size();
    local_queues_.emplace_back(std::make_unique<WorkStealingQueue>());
    threads_.emplace_back(std::make_unique<std::thread>(&ThreadPool::worker_thread, this, thread_id));
}

WorkStealingQueue* ThreadPool::get_local_queue() {
    static thread_local size_t thread_id = get_thread_id();
    if (thread_id < local_queues_.size()) {
        return local_queues_[thread_id].get();
    }
    return nullptr;
}

size_t ThreadPool::get_thread_id() {
    static std::atomic<size_t> counter{0};
    static thread_local size_t id = counter.fetch_add(1);
    return id;
}

size_t ThreadPool::thread_count() const {
    return active_threads_.load();
}

size_t ThreadPool::pending_task_count() const {
    return pending_tasks_.load();
}

bool ThreadPool::is_idle() const {
    return pending_tasks_.load() == 0;
}

void ThreadPool::wait_for_tasks() {
    while (!is_idle()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void ThreadPool::shutdown() {
    if (shutdown_.exchange(true)) {
        return;
    }
    
    condition_.notify_all();
    
    for (auto& thread : threads_) {
        if (thread && thread->joinable()) {
            thread->join();
        }
    }
    
    threads_.clear();
    local_queues_.clear();
}

const ThreadPoolConfig& ThreadPool::config() const {
    return config_;
}

} // namespace thread_pool
