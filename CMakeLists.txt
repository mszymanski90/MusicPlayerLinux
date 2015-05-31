cmake_minimum_required(VERSION 2.8.11)

project(MusicPlayerLinux)

set(MusicPlayerLinux_VERSION_MAJOR 0)
set(MusicPlayerLinux_VERSION_MINOR 1)
set(MusicPlayerLinux_VERSION_PATCH 0)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)

include_directories(src
    src/core
    bass
    /usr/include/taglib
    ${CMAKE_CURRENT_BINARY_DIR})

add_executable(mpl src/main.cpp
    src/loggerdevice.cpp
    src/mainapplication.cpp
    src/mainwindow.cpp
    src/playlistmodel.cpp
    src/qseekslider.cpp
    src/qvolumeslider.cpp
    src/tagextractor.cpp
    src/core/bassplayer.cpp
    src/core/core.cpp
    src/core/iplayer.cpp
    src/core/iplayerobserver.cpp
    src/core/iplayerstate.cpp
    src/core/stateidle.cpp
    src/core/statepaused.cpp
    src/core/stateplayback.cpp
    src/mainwindow.ui)

target_link_libraries(mpl Qt5::Widgets)
target_link_libraries(mpl ${CMAKE_SOURCE_DIR}/bass/x64/libbass.so)
target_link_libraries(mpl tag)
