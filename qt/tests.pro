TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

HEADERS += \
    ../src/camera.h \
    ../src/drawmanager.h \
    ../src/drawobject.h \
    ../src/drawpointbyshader.h \
    ../src/drawpointshader.h \
    ../src/drawquad.h \
    ../src/fileutility.h \
    ../src/line.h \
    ../src/mlog.h \
    ../src/mwindow.h \
    ../src/shader.h

SOURCES += \
    ../src/camera.cpp \
    ../src/drawmanager.cpp \
    ../src/drawpointbyshader.cpp \
    ../src/drawpointshader.cpp \
    ../src/drawquad.cpp \
    ../src/fileutility.cpp \
    ../src/line.cpp \
    ../src/main.cpp \
    ../src/mlog.cpp \
    ../src/mwindow.cpp \
    ../src/shader.cpp

OTHER_FILES += \
    ../shaders/draw_point.frag \
    ../shaders/draw_point.vert


LIBS += -lSDL2 -lGL -lGLEW

include(deployment.pri)
qtcAddDeployment()


