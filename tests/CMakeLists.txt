cmake_minimum_required(VERSION 3.0.0)
project(tests)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

enable_testing()

add_executable(tests "../dbInteraction.cpp")

target_link_libraries(tests tests.cpp)