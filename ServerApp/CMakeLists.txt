cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)

project(ServerApp)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ServerLib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ServerLib)
