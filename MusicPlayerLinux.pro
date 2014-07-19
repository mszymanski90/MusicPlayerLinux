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
QMAKE_CXXFLAGS += -std=gnu++0x

linux-g++ {
     LIBS += $$PWD/libbass.so
 }

win32-g++ {
     LIBS += $$PWD/bass.lib
 }

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp \
    mplcore.cpp \
    loggerdevice.cpp \
    mpl_abstractstate.cpp \
    mpl_stateplayback.cpp \
    mpl_stateidle.cpp \
    mpl_statepaused.cpp \
    mpl_bassdevice.cpp

HEADERS  += mainwindow.h \
    bass.h \
    mainapplication.h \
    mplcore.h \
    loggerdevice.h \
    mpl_abstractstate.h \
    mpl_stateplayback.h \
    mpl_stateidle.h \
    mpl_statepaused.h \
    mpl_bassdevice.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    COPYING
