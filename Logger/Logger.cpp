#include "Logger.hpp"

#include <iostream>

namespace AP
{
    Logger::Logger(/* args */)
    {
        m_thread = std::thread{&Logger::process_entries, this};
    }

    Logger::~Logger()
    {
        {
            std::unique_lock lock(m_mutex);
            m_stop = true;
        }

        m_cond_var.notify_all();
        m_thread.join();
    }

    void Logger::log(std::string_view entry)
    {
        std::unique_lock lock{m_mutex};
        m_queue.push_back(move(std::string(entry)));
        m_cond_var.notify_all();
    }

    void Logger::test_swap()
    {
        EntriesQueue new_queue;

        for (int var = 0; var < 5; ++var)
        {
            new_queue.push_back(std::to_string(var));
        }

        m_queue.swap(new_queue);
    }

    void Logger::process_entries()
    {
        std::ofstream logFile { "log.txt" };
        if (logFile.fail()) 
        {
            std::cerr << "Failed to open logfile." << std::endl;
            return;
        }
        // Create a lock for m_mutex, but do not yet acquire a lock on it.
        std::unique_lock lock { m_mutex, std::defer_lock };
        // Start processing loop.
        while (true)
        {
            lock.lock();
            // Wait for a notification.

            if (!m_stop)
            {
                m_cond_var.wait(lock);
            }
            else
            {
                process_entries_helper(m_queue, logFile);
                break;
            }
            // Condition variable is notified, so something might be in the queue.
            // While we still have the lock, swap the contents of the current queue
            // with an empty local queue on the stack.
            EntriesQueue localQueue;
            localQueue.swap(m_queue);
            // Now that all entries have been moved from the current queue to the
            // local queue, we can release the lock so other threads are not blocked
            // while we process the entries.
            lock.unlock();
            // Process the entries in the local queue on the stack. This happens after
            // having released the lock, so other threads are not blocked anymore.
            process_entries_helper(localQueue, logFile);
        }
    }

    void Logger::process_entries_helper(EntriesQueue& queue, std::ofstream& ofs) const
    {
        while (!queue.empty())
        {
            ofs<<queue.front()<<std::endl;
            queue.pop_front();
        }
    }

} // namespace AP
