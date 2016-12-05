QT += core sql
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
    main.cpp \
    computers.cpp

HEADERS += \
    service.h \
    database.h \
    console.h \
    scientist.h \
    errorhandling.h \
    computers.h

DISTFILES += \
    data.db \
    data.txt \
