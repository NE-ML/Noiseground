cmake_minimum_required(VERSION 3.10)
project(httpClient)

set(CMAKE_CXX_STANDARD 20)

include_directories(httpClient)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

find_package(Boost REQUIRED)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(httpClient_run main.cpp httpClient/httpClient.cpp httpClient/deserializer.cpp)
    target_link_libraries(httpClient_run ${Boost_LIBRARIES})
endif()