QT += sql
TEMPLATE = app
linux-g++ { 
    PLATFORM = x86
    QMAKE_CFLAGS += -pg
    QMAKE_CXXFLAGS += -pg
    QMAKE_LFLAGS += -pg
}
linux-mips-g++:PLATFORM = mips
linux-arm-g++:PLATFORM = arm
win32-g++ { 
    PLATFORM = win32
    DESTDIR = ../A6sale_touch
}
message("$$PLATFORM")
MOC_DIR = .$${PLATFORM}_moc
OBJECTS_DIR = .$${PLATFORM}_obj
SOURCES += main.cpp \
    emenu.cpp \
    discountitem.cpp \
    healthitem.cpp \
    storyselectitem.cpp \
    emenuenv.cpp \
    emenudata.cpp \
    discountpriceitem.cpp \
    storytextitem.cpp \
    welcompage.cpp \
    customerpage.cpp \
    discountpage.cpp \
    healthpage.cpp \
    commonmenupage.cpp \
    aanimationpage.cpp \
    featurequerypage.cpp \
    agraphicsselectitem.cpp \
    recommendationitem.cpp \
    recommendationpage.cpp \
    rankpage.cpp \
    rankitem.cpp \
    storypage.cpp \
    commonmenuitem.cpp \
    commondetail.cpp \
    featurequeryitem.cpp \
    acontrolbutton.cpp \
    healthkinditem.cpp
HEADERS += emenu.h \
    dishdata.h \
    discountitem.h \
    agraphicspixmapobject.h \
    agraphicsrectobject.h \
    healthitem.h \
    storyselectitem.h \
    emenuenv.h \
    emenudata.h \
    discountpriceitem.h \
    storytextitem.h \
    welcompage.h \
    customerpage.h \
    discountpage.h \
    healthpage.h \
    commonmenupage.h \
    aanimationpage.h \
    featurequerypage.h \
    agraphicsselectitem.h \
    recommendationitem.h \
    recommendationpage.h \
    rankpage.h \
    rankitem.h \
    storypage.h \
    commonmenuitem.h \
    commondetail.h \
    featurequeryitem.h \
    acontrolbutton.h \
    healthkinditem.h
FORMS += 
OTHER_FILES += 
