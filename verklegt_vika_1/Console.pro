QT += core
QT -= gui

CONFIG += c++11

TARGET = Console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    console.cpp \
    database.cpp

HEADERS += \
    console.h \
    database.h
