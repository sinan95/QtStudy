#-------------------------------------------------
#
# Project created by QtCreator 2020-04-02T09:37:29
#
#-------------------------------------------------

QT       -= gui

TARGET = Design
TEMPLATE = lib

DEFINES += DESIGN_LIBRARY

SOURCES += \
    observer.cpp

HEADERS +=\
        design_global.h \
    observer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
