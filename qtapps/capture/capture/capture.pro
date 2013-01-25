#-------------------------------------------------
#
# Project created by QtCreator 2010-10-28T12:08:44
#
#-------------------------------------------------

QT       += core gui network

TARGET = capture
TEMPLATE = app

LIBS += -lcv \
        -lhighgui

INCLUDEPATH +=/home/tsuibin/source/opencvlibrary/opencv/include/opencv

SOURCES += main.cpp\
        capture.cpp \
    videoserver.cpp \
    framework.cpp \
    capturethread.cpp

HEADERS  += capture.h \
    videoserver.h \
    framework.h \
    capturethread.h

FORMS    += capture.ui
