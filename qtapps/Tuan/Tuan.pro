#-------------------------------------------------
#
# Project created by QtCreator 2011-05-19T20:42:45
#
#-------------------------------------------------

QT       += core gui network webkit

TARGET = Tuan
TEMPLATE = app


SOURCES += main.cpp\
        tuan.cpp \
    goods.cpp \
    downloadpicture.cpp \
    favitem.cpp \
    map.cpp

HEADERS  += tuan.h \
    goods.h \
    downloadpicture.h \
    favitem.h \
    map.h

FORMS    += \
    goods.ui \
    favitem.ui \
    map.ui

OTHER_FILES += \
    map.html
