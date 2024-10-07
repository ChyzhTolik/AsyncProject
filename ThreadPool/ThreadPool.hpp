#pragma once

#include <string_view>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <fstream>
#include <vector>
#include <functional>
#include <future>
#include <exception>

namespace AP
{
    class ThreadPool
    {
    public:
        ThreadPool(size_t num_of_threads = 1);
        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator = (const ThreadPool&) = delete;
        ~ThreadPool();

        /*Auto auto-derived type, Args... indefinite parameter list, -> xxx return value type
        Add a task*/
        template <class F, class... Args>
        auto enqueue(F&& f, Args&&... args)->std::future<typename std::invoke_result<F, Args...>::type>
        {
            // Custom return value type Similar to the usage of typedef
            using return_type = typename std::invoke_result<F, Args...>::type;
            auto task = std::make_shared<std::packaged_task<return_type()>>(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
                );
            // std::future concurrent programming bind task
            std::future<return_type> res = task->get_future();
            {
                std::unique_lock<std::mutex> lock(this->m_queue_mutex);
                // Determine whether the ThreadPool stops
                if (m_stop)
                {
                    throw std::runtime_error("enqueue on stopped ThreadPool!\n");
                }                
                // Add task to task list
                m_tasks.emplace([task]() { (*task)(); });
            }
            m_con_var.notify_one(); // wake up a task
            return res;
        }

    private:
        // thread container that executes the task
        std::vector<std::thread> m_workers; 
        // function<> function wrapper, task queue
        std::queue<std::function<void()>> m_tasks;
        // Mutex
        std::mutex m_queue_mutex; 
        // conditional lock
        std::condition_variable m_con_var;
        // determine whether to stop the thread pool
        bool m_stop; 
    };
    
    
    
} // namespace AP
