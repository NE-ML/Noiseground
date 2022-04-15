cmake_minimum_required(VERSION 3.5)

project(Noiseground LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(UI_SOURCES 
        src/main.cpp
        src/mainwindow.cpp
        src/auth_dialog.cpp
        src/sign_up_dialog.cpp
        src/userwindow.cpp
        src/UIManager.cpp)

set(UI_HEADERS
        include/mainwindow.h
        include/auth_dialog.h
        include/sign_up_dialog.h
        include/userwindow.h
        include/UIManager.h)

add_executable(${PROJECT_NAME} ${UI_SOURCES} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tst tests/test.cpp)
target_link_libraries(tst Qt5::Widgets ${GTEST_LIBRARIES})