TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

HEADERS += \
    line.h \
    drawmanager.h \
    drawobject.h \
    shader.h \
    mlog.h \
    fileutility.h \
    drawquad.h \
    mwindow.h \
    drawpointbyshader.h \
    drawpointshader.h \
    camera.h

SOURCES += \
    line.cpp \
    drawmanager.cpp \
    main.cpp \
    shader.cpp \
    mlog.cpp \
    fileutility.cpp \
    drawquad.cpp \
    mwindow.cpp \
    drawpointbyshader.cpp \
    drawpointshader.cpp \
    camera.cpp

OTHER_FILES += \
    shaders/draw_point.vert \
    shaders/draw_point.frag


LIBS += -lSDL2 -lGL -lGLEW

include(deployment.pri)
qtcAddDeployment()

#DISTFILES += \
#    shaders/draw_point.frag \
#    shaders/draw_point.vert

