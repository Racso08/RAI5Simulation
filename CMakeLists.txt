cmake_minimum_required(VERSION 3.9)
project(ClionTest)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Xml REQUIRED)

add_executable(ClionTest main.cpp)

target_link_libraries(ClionTest Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Xml)

