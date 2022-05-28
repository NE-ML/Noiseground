cmake_minimum_required(VERSION 3.10)
project(httpClient)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

find_package(Boost COMPONENTS ALL REQUIRED)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS} httpClient httpClientManager)

    add_library(serializer httpClient/serializer.cpp)

    add_library(httpClient httpClient/httpClient.cpp)
    target_link_libraries(httpClient serializer)

    add_library(httpClientManager httpClientManager/httpClientManager.cpp)
    target_link_libraries(httpClientManager httpClient serializer)

    add_executable(httpClient_run main.cpp)
    target_link_libraries(httpClient_run ${Boost_LIBRARIES})
    target_link_libraries(httpClient_run httpClientManager)
endif()