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
        src/MainWindow.cpp
        src/AuthDialog.cpp
        src/SignUpDialog.cpp
        src/UserWindow.cpp
        src/UIManager.cpp
        src/SoundBox.cpp
        src/PlayPauseButton.cpp)

set(UI_HEADERS
        include/MainWindow.h
        include/AuthDialog.h
        include/SignUpDialog.h
        include/UserWindow.h
        include/UIManager.h
        include/SoundBox.h
        include/PlayPauseButton.h)

add_executable(${PROJECT_NAME} src/main.cpp ${UI_SOURCES} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tst tests/test.cpp ${UI_SOURCES} ${UI_HEADERS})
target_link_libraries(tst Qt5::Widgets ${GTEST_LIBRARIES})