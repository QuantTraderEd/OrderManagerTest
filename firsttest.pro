#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T10:51:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = firsttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11
INCLUDEPATH += /usr/local/boost-1.57/include
LIBS += -lboost_system

TEMPLATE = app

SOURCES += \
    main.cc \
    exampleModule.cc

HEADERS += \
    types.h \
    exampleModule.h \
    orderServer.h
