cmake_minimum_required(VERSION 3.0.0)
project(headers)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(Sound_Final sfml-graphics sfml-audio)