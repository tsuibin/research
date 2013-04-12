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
    gridview.cpp \
    randomview.cpp \
    createalbum.cpp \
    filtermenu.cpp \
    preview.cpp \
    topmenu.cpp \
    albumpreview.cpp \
    imglabel.cpp \
    appenv.cpp

HEADERS  += touchdemo.h \
    gridview.h \
    randomview.h \
    createalbum.h \
    filtermenu.h \
    preview.h \
    topmenu.h \
    albumpreview.h \
    imglabel.h \
    appenv.h \
    common.h

FORMS    += touchdemo.ui \
    gridview.ui \
    randomview.ui \
    createalbum.ui \
    filtermenu.ui \
    preview.ui \
    topmenu.ui \
    albumpreview.ui

OTHER_FILES += \
    images/save_active.png \
    images/save.png \
    images/ret_active.png \
    images/ret.png \
    images/random_active.png \
    images/random.png \
    images/random.jpg \
    images/menu_bg.jpg \
    images/gird_active.png \
    images/gird.png \
    images/filter_active.png \
    images/filter.png \
    images/edit_active.jpg \
    images/edit.png \
    images/del_active.png \
    images/del.png \
    images/cut_active.png \
    images/cut.png \
    images/cut.jpg \
    images/create_active.png \
    images/create.png \
    images/bg.jpg \
    images/4x-2.png \
    images/4x.png \
    images/2x-2.png \
    images/2x.png \
    images/1x-2.png \
    images/1x.png
