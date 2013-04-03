SOURCES = main.cpp
RESOURCES = animatedtiles.qrc

# install
target.path = animatedtiles
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS animatedtiles.pro images
sources.path = animatedtiles
INSTALLS += target sources
