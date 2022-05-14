cmake_minimum_required(VERSION 3.21)
project(Noiseground_sound)

set(CMAKE_CXX_STANDARD 20)
include_directories(Frameworks/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

enable_testing()
find_package(GTest REQUIRED)

add_executable(tests tests/tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES})
