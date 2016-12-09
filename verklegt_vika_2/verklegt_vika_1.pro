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
    computer.cpp \
    cputype.cpp \
    errorlog.cpp \
    mytime.cpp \
    activitylog.cpp

HEADERS += \
    service.h \
    database.h \
    console.h \
    scientist.h \
    errorhandling.h \
    computer.h \
    cputype.h \
    errorlog.h \
    dependances.h \
    mytime.h \
    activitylog.h

DISTFILES += \
    data.db \
    data.txt \
