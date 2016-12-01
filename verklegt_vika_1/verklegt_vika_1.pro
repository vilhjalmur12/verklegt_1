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
<<<<<<< HEAD
    main.cpp
=======
    main.cpp \
>>>>>>> 04b1c5a420399cb2e72e6bf56fcd94ab03d99b73

HEADERS += \
    service.h \
    database.h \
    console.h \
    scientist.h \
    errorhandling.h

DISTFILES += \
    data.db \
    data.txt \
<<<<<<< HEAD
=======

>>>>>>> 04b1c5a420399cb2e72e6bf56fcd94ab03d99b73
