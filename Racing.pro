#-------------------------------------------------
#
# Project created by QtCreator 2014-04-15T06:30:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Racing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    car.cpp \
    track.cpp \
    about.cpp \
    documentation.cpp \
    viewtable.cpp \
    racetype.cpp \
    previousdata.cpp

HEADERS  += mainwindow.h \
    car.h \
    track.h \
    about.h \
    documentation.h \
    viewtable.h \
    racetype.h \
    previousdata.h

FORMS    += \
    car.ui \
    track.ui \
    about.ui \
    documentation.ui \
    viewtable.ui \
    racetype.ui \
    mainwindow.ui \
    previousdata.ui

RESOURCES += \
    Resources.qrc
