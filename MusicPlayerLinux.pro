#
#    Copyright (c) 2014 Maciej Szymański, Volodymyr Tsiesielski
#
#    This file is part of Music Player Linux.
#
#    Music Player Linux is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    Music Player Linux is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Music Player Linux; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicPlayerLinux
TEMPLATE = app
CONFIG += c++11

linux-g++ {
     LIBS += $$PWD/lib/libbass.so
 }

win32-g++ {
     LIBS += $$PWD/lib/bass.lib
 }

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp \
    core/core.cpp \
    loggerdevice.cpp \
    core/iplayerstate.cpp \
    core/stateplayback.cpp \
    core/stateidle.cpp \
    core/statepaused.cpp \
    core/bassplayer.cpp \
    core/iplayer.cpp

HEADERS  += mainwindow.h \
    bass.h \
    mainapplication.h \
    core/core.h \
    loggerdevice.h \
    core/iplayerstate.h \
    core/stateplayback.h \
    core/stateidle.h \
    core/statepaused.h \
    core/bassplayer.h \
    core/iplayer.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    COPYING


