cmake_minimum_required(VERSION 3.22)
project(NoisegroundTestIntegration)

set(CMAKE_CXX_STANDARD 11)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


include_directories(NewSound/headers UI/include common HttpClient/httpClient HttpClient/httpClientManager)

add_subdirectory(UI)
add_subdirectory(NewSound)
add_subdirectory(HttpClient)


set(COMMON_SRC common/main.cpp common/Core.cpp)


add_executable(main ${COMMON_SRC})

target_link_libraries(main UI Sound httpClientManager sfml-audio sfml-graphics sfml-system Qt5::Widgets)