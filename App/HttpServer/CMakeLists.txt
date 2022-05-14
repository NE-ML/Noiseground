cmake_minimum_required(VERSION 3.10)
project(httpServer)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost COMPONENTS ALL REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR} httpServer httpServer/managers ../httpClient/httpClient)

#    add_library(UserManager httpServer/managers/userManager.cpp httpServer/managers/serializer.cpp)
    add_library(SoundManager httpServer/managers/soundManager.cpp httpServer/managers/serializer.cpp)

    add_library(httpServer httpServer/httpServer.cpp httpServer/httpConnection.cpp httpServer/router.cpp
                            httpServer/parser.cpp httpServer/reply.cpp httpServer/mime_types.cpp)

    target_link_libraries(httpServer SoundManager)

    add_executable(httpServer_run main.cpp)
    target_link_libraries(httpServer_run httpServer)
    target_link_libraries(httpServer_run ${Boost_LIBRARIES})
    target_link_libraries(httpServer_run pthread)
endif()