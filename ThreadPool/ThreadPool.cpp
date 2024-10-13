#include "ThreadPool.hpp"

#include <iostream>

namespace AP
{
    ThreadPool::ThreadPool(size_t num_of_threads) : m_stop(false)
    {
        for (size_t i = 0; i < num_of_threads; i++) 
        {
            // Add worker thread to workers
            m_workers.reserve(num_of_threads);
            m_workers.emplace_back(
                [this] 
                {
                    // Let the thread continue to work,
                    for (;;) 
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(this->m_queue_mutex); // Mutex is turned on until the end of the life cycle
                            // If the queue of tasks are empty, temporarily block the thread
                            this->m_con_var.wait(lock,[this] { return this->m_stop || !this->m_tasks.empty(); });
                            if (this->m_stop && this->m_tasks.empty())
                                return;
                            task = std::move(this->m_tasks.front()); // Assign the first value of the tasks to the task in the form of an rvalue
                            this->m_tasks.pop(); // pop the elements of the task just assigned to the task
                        }
                        task(); // Let the thread execute the function
                    }
                }
            );
        }
    }
    
    ThreadPool::~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock(this->m_queue_mutex);
            m_stop = true;
        }
        m_con_var.notify_all(); // wake up all tasks

        for (std::thread& worker : m_workers)
        {
            worker.join(); // Thread automatically adds mutex lock execution, detach is concurrent execution
        }
    }

} // namespace AP
