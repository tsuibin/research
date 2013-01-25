#-------------------------------------------------
#
# Project created by QtCreator 2010-11-09T15:16:32
#
#-------------------------------------------------

QT       += core gui network

TARGET = ipvs_client
TEMPLATE = app

unix:LIBS += -lcv \
    -lhighgui

SOURCES += main.cpp\
        imageclient.cpp

HEADERS  += imageclient.h

FORMS    += imageclient.ui
