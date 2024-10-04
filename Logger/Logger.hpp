#pragma once

#include <string_view>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <fstream>
#include "tsqueue.hpp"

namespace AP
{
    // using EntriesQueue = std::deque<std::string>;
    using EntriesQueue = AP::net::tsqueue<std::string>;

    class Logger
    {
    public:
        Logger();
        ~Logger();
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        void log(std::string_view entry);
        void test_swap();
    private:
        void process_entries();
        void process_entries_helper(EntriesQueue& queue, std::ofstream& ofs) const;

        std::mutex m_mutex;
        std::condition_variable m_cond_var;
        EntriesQueue m_queue;
        std::thread m_thread;
        bool m_stop{false};
    };
} // namespace AP
