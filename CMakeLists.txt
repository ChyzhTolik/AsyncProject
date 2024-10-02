cmake_minimum_required(VERSION 3.28.0)

add_executable(AsyncProject main.cpp)

add_subdirectory(ServerLib)
add_subdirectory(ServerApp)
add_subdirectory(ClientApp)