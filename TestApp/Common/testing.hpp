#pragma once

#include <exception>
#include <atomic>


namespace Test
{
    class Calculator
    {
    public:
        explicit Calculator(int a, int b) : m_a { a }, m_b { b } {}
        void operator()() { result = m_a * m_b; }
        int getResult() const { return result; }
    private:
        int m_a { 0 };
        int m_b { 0 };
        int result { 0 };
    };

    void get_results_from_thread();

    void test_thread_with_exception();
    void atomicallyMultiply(std::atomic<int>& a, int n);
    void test_atomics();
    void test_atomics_with_wait();

    void test_logger();
    void test_logger_swap();
    void test_thread_pool();

} // namespace Test
