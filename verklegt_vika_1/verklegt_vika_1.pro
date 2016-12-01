QT += core
QT -= gui

CONFIG += c++11

TARGET = verklegt_vika_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    service.cpp \
    database.cpp \
    console.cpp \
    scientist.cpp \
    errorhandling.cpp \
    ../../main.cpp

HEADERS += \
    service.h \
    database.h \
    console.h \
    scientist.h \
    errorhandling.h

DISTFILES += \
    data.txt
    ../build-verklegt_vika_1-Desktop_Qt_5_7_0_MinGW_32bit-Debug/data.db
