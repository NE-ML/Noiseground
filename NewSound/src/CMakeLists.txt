cmake_minimum_required(VERSION 3.21)
project(src)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS audio graphics system REQUIRED)

include_directories(../headers)


set(SRCS_SOUND Sound.cpp)

add_library(Sound STATIC ${SRCS_SOUND})

#target_link_libraries(Sound sfml-audio sfml-graphics sfml-system)