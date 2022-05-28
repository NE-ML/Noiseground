cmake_minimum_required(VERSION 3.10)
project(Noiseground)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(headers)

add_library(Sound src/Sound.cpp)

enable_testing()
include_directories(Frameworks/googletest/googletest/include)
find_package(GTest REQUIRED)

add_executable(tests tests/tests.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES})
