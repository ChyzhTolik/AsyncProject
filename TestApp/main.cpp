#include "Common/testing.hpp"

#include <iostream>

int main()
{
    std::cout<<"Started TestApp"<<std::endl;

    Test::test_thread_pool();

    std::cout<<"Done"<<std::endl;

    // std::cin.get();
    return 0;
}
