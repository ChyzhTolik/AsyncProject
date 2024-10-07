cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)

project(TestApp)

set(HEADERS
    Common/testing.hpp
)

set(SOURCES
    main.cpp
    Common/testing.cpp
)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
target_link_libraries(${PROJECT_NAME} Logger)
target_link_libraries(${PROJECT_NAME} ThreadPool)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Logger)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ThreadPool)

