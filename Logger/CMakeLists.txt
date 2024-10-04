cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

project(Logger)

set(HEADERS 
    Logger.hpp
    tsqueue.hpp
)
set(SOURCES
    Logger.cpp
)
add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

if(UNIX)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
    
endif(UNIX)

