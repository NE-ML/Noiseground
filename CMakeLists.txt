cmake_minimum_required(VERSION 3.0.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled dbInteraction.cpp DatabaseInteraction.h)

add_subdirectory(tests)

find_package(GTest REQUIRED)