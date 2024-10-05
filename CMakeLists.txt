cmake_minimum_required(VERSION 3.28.0)
set(CMAKE_CXX_STANDARD 17)

project(AsyncProject)
add_executable(AsyncProject main.cpp)


add_subdirectory(ServerLib)
add_subdirectory(ServerApp)
add_subdirectory(ClientApp)
add_subdirectory(TestApp)
add_subdirectory(Logger)
add_subdirectory(TestQT)
