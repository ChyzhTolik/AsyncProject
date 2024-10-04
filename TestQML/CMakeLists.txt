cmake_minimum_required(VERSION 3.26)


project(TestQML LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STA ON)

set(HEADERS
    Firefox.hpp
    Userinteractor.hpp
    InternetExplorer.hpp
)

set(SOURCES
    main.cpp
    Firefox.cpp
    Userinteractor.cpp
    InternetExplorer.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}

     )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
