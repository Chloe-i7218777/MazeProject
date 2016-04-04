TARGET=bin/Maze

OBJECTS_DIR=obj
INCLUDEPATH+=$$PWD/include

MOC_DIR=moc

SOURCES+=$$PWD/src/main.cpp \
         $$PWD/src/Maze.cpp


HEADERS+=$$PWD/include/Maze.h


OTHER_FILES +=$$PWD/shaders/*.glsl

QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
LIBS+=$$system(sdl2-config --libs)
include($(HOME)/NGL/UseNGL.pri)
OTHER_FILES += README.md

DISTFILES +=
