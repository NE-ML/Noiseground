cmake_minimum_required(VERSION 3.21)
project(src)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS audio graphics system REQUIRED)

include_directories(../headers)
include_directories(../music_example/)

set(SRCS_SOUND Sound.cpp)

add_executable(src ${SRCS_SOUND} execute.cpp)

target_link_libraries(src sfml-audio sfml-graphics sfml-system)