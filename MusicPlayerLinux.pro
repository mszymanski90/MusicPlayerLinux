#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T09:13:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicPlayerLinux
TEMPLATE = app

LIBS += $$PWD/libbass.so

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp \
    mplcore.cpp \
    loggerdevice.cpp

HEADERS  += mainwindow.h \
    bass.h \
    mainapplication.h \
    mplcore.h \
    loggerdevice.h

FORMS    += mainwindow.ui
