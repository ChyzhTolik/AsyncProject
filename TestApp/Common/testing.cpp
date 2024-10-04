#include "testing.hpp"

#include "included_headers.hpp"

namespace Test
{
    void get_results_from_thread()
    {
        Calculator calc{21,2};

        std::thread job(std::ref(calc));

        job.join();

        std::cout<<"21*2="<<calc.getResult()<<std::endl;
    }

    void doSomeWork()
    {
        for (int i { 0 }; i < 5; ++i) { std::cout<< i <<std::endl; }
        std::cout<<"Thread throwing a runtime_error exception..."<<std::endl;
        throw std::runtime_error { "Exception from thread" };
    }

    void thread_with_exceptions(std::exception_ptr& err)
    {
        try 
        {
            doSomeWork();
        } 
        catch (...) 
        {
            std::cout<<"Thread caught exception, returning exception..."<<std::endl;
            err = std::current_exception();
        }
    }

    void doWorkInThread()
    {
        std::exception_ptr error;
        // Launch thread.
        std::thread t { thread_with_exceptions, std::ref(error) };
        // Wait for thread to finish.
        t.join();
        // See if thread has thrown any exception.
        if (error) 
        {
            std::cout<<"Main thread received exception, rethrowing it..."<<std::endl;
            rethrow_exception(error);
        } 
        else 
        {
            std::cout<<"Main thread did not receive any exception."<<std::endl;
        }
    }

    void test_thread_with_exception()
    {
        try
        {
            doWorkInThread();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Main function caught:"<< e.what() << '\n';
        }
    }

    void atomicallyMultiply(std::atomic<int>& a, int n)
    {
        int expected { a.load() };
        int desired { n * expected };

        while (!a.compare_exchange_strong(expected, desired)) 
        {
            desired = n * expected;
        }
    }

    void increment(std::atomic<int>& counter)
    {
        using namespace std::chrono_literals;
        
        for (int i { 0 }; i < 100; ++i) 
        {
            ++counter;
            std::this_thread::sleep_for(1ms);
        }
    }

    void test_atomics()
    {
        std::atomic<int> counter { 0 };
        std::vector<std::thread> threads;
        for (int i { 0 }; i < 10; ++i) 
        {
            threads.emplace_back(increment, std::ref(counter));
        }
        for (auto& t : threads) { t.join(); }
        std::cout<<"Result = "<< counter<<std::endl;
    }

    void test_atomics_with_wait()
    {
        using namespace std::chrono_literals;

        std::atomic<int> value { 0 };
        std::thread job { [&value] {
            std::cout<<"Thread starts waiting."<<std::endl;
            // value.wait(0);
            std::cout<<"Thread wakes up, value ="<< value.load()<<std::endl;
        } };
        std::this_thread::sleep_for(2s);
        std::cout<<"Main thread is going to change value to 1."<<std::endl;
        value = 1;
        // value.notify_all();
    }

    void log_some_messages(uint16_t id, AP::Logger& logger)
    {
        for (size_t i = 0; i < 10; i++)
        {
            logger.log("Log entry "+std::to_string(i)+" from thread "+std::to_string(id));
        }
    }

    void test_logger()
    {
        using namespace std::chrono_literals;
        AP::Logger logger;

        std::vector<std::thread> threads;

        for (size_t i = 0; i < 10; i++)
        {
            // threads.emplace_back(log_some_messages, i, std::ref(logger));
            log_some_messages(i,logger);
        }

        for (auto &&t : threads)
        {
            t.join();
        }

    }

    void test_logger_swap()
    {
        AP::Logger logger;

        for (int var = 0; var < 10; ++var)
        {
            logger.log("Hello");
        }

        logger.test_swap();
    }

} // namespace Test
