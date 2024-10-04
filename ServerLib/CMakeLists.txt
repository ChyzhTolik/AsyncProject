cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)

project(ServerLib)

set(HEADERS 
    Common/serverlib_headers.hpp
    Common/net_common.hpp
    Common/tsqueue.hpp
)
set(SOURCES
    Server/Server.cpp
    Client/Client.cpp
)
add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

set (INCLUDES ${CMAKE_SOURCE_DIR}/external/include)

if(UNIX)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads)    
    
endif(UNIX)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
target_include_directories(${PROJECT_NAME} PUBLIC Common)
