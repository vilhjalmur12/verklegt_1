QT += core
QT -= gui

CONFIG += c++11

TARGET = verklegt_vika_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    service.cpp \
    database.cpp \
    console.cpp

HEADERS += \
    service.h \
    database.h \
    console.h
