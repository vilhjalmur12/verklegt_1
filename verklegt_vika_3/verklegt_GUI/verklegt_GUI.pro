#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T08:41:41
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verklegt_GUI
TEMPLATE = app


SOURCES += main.cpp\
    DATA/database.cpp \
    Domain/activitylog.cpp \
    Domain/computer.cpp \
    Domain/cputype.cpp \
    Domain/errorhandling.cpp \
    Domain/errorlog.cpp \
    Domain/mytime.cpp \
    Domain/scientist.cpp \
    Domain/service.cpp \
    UI/loginwindow.cpp \
    UI/errorwindow.cpp \
    UI/createuserwindow.cpp \
    UI/mainwindow.cpp \
    UI/editstudentdialog.cpp \
    UI/editcomputerdialog.cpp \
    UI/recycledbin.cpp \
    editcomputersrelations.cpp \
    UI/editscientistsrelations.cpp \
    UI/insertscientist.cpp \
    UI/insertcomputerdialog.cpp


HEADERS  += \
    DATA/database.h \
    Domain/activitylog.h \
    Domain/computer.h \
    Domain/cputype.h \
    Domain/dependances.h \
    Domain/errorhandling.h \
    Domain/errorlog.h \
    Domain/mytime.h \
    Domain/scientist.h \
    Domain/service.h \
    UI/loginwindow.h \
    UI/errorwindow.h \
    UI/createuserwindow.h \
    UI/mainwindow.h \
    UI/editstudentdialog.h \
    UI/editcomputerdialog.h \
    UI/recycledbin.h \
    editcomputersrelations.h \
    UI/editscientistsrelations.h \
    UI/insertscientist.h \
    UI/insertcomputerdialog.h


FORMS    += \
    UI/loginwindow.ui \
    UI/errorwindow.ui \
    UI/createuserwindow.ui \
    UI/mainwindow.ui \
    UI/editstudentdialog.ui \
    UI/editcomputerdialog.ui \
    UI/recycledbin.ui \
    editcomputersrelations.ui \
    UI/editscientistsrelations.ui \
    UI/insertscientist.ui \
    UI/insertcomputerdialog.ui


DISTFILES +=

RESOURCES += \
    resources.qrc

STATECHARTS +=
