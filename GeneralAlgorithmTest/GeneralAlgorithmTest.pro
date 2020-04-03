#-------------------------------------------------
#
# Project created by QtCreator 2020-04-03T09:35:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneralAlgorithmTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    ../GeneralAlgorithm/generalalgorithm_global.h \
    ../GeneralAlgorithm/similarity.h

FORMS    += widget.ui

include(../base.pri)
LIBS += -L$$PROJECT_LIBDIR -lGeneralAlgorithm
