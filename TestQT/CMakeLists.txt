cmake_minimum_required(VERSION 3.26)


project(TestQT LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STA ON)

set(HEADERS
    Classes/Firefox.hpp
    Classes/Userinteractor.hpp
    Classes/InternetExplorer.hpp
    testing.hpp
    included_headers.hpp
    Classes/ApplicationWindow.hpp
)

set(SOURCES
    main.cpp
    Classes/Firefox.cpp
    Classes/Userinteractor.cpp
    Classes/InternetExplorer.cpp
    testing.cpp
    Classes/ApplicationWindow.cpp
    qml/example.qml
)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}


     )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
