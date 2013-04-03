#-------------------------------------------------
#
# Project created by QtCreator 2013-04-03T09:49:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = touchdemo
TEMPLATE = app


SOURCES += main.cpp\
        touchdemo.cpp \
    girdview.cpp \
    randomview.cpp \
    createalbum.cpp \
    filtermenu.cpp \
    preview.cpp \
    topmenu.cpp \
    albumpreview.cpp

HEADERS  += touchdemo.h \
    girdview.h \
    randomview.h \
    createalbum.h \
    filtermenu.h \
    preview.h \
    topmenu.h \
    albumpreview.h

FORMS    += touchdemo.ui \
    girdview.ui \
    randomview.ui \
    createalbum.ui \
    filtermenu.ui \
    preview.ui \
    topmenu.ui \
    albumpreview.ui
