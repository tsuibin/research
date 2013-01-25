
LIBS += -lcv -lhighgui

SOURCES += \
    main.cpp \
    camera.cpp \
    framebuffer.cpp \
    play.cpp \
    server.cpp

OTHER_FILES += \
    start.sh \
    webcameraclient.pro.user

HEADERS += \
    camera.h \
    framebuffer.h \
    play.h \
    server.h
