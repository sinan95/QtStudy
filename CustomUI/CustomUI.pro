#-------------------------------------------------
#
# Project created by QtCreator 2020-03-31T16:12:52
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = CustomUI
TEMPLATE = lib

DEFINES += CUSTOMUI_LIBRARY

SOURCES += customui.cpp \
    transparentwaitwidget.cpp \
    drtoolbutton.cpp

HEADERS += customui.h\
    customui_global.h \
    transparentwaitwidget.h \
    drtoolbutton.h

include(../base.pri)

RESOURCES += \
    image.qrc

