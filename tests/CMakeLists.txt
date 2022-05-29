cmake_minimum_required(VERSION 3.10)
project(tests)

set(CMAKE_CXX_STANDARD 14)

include_directories(../HttpClient/httpClient ../App/HttpServer/httpServer
        ../App/HttpServer/httpServer/managers)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

find_package(Boost REQUIRED)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests tests.cpp)
target_link_libraries(tests ${Boost_LIBRARIES})
target_link_libraries(tests m pthread ${GTEST_LIBRARIES})