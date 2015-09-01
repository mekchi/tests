TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    line.cpp \
    drawmanager.cpp \
    main.cpp \
    shader.cpp

LIBS += -lSDL2

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    line.h \
    drawmanager.h \
    drawobject.h \
    shader.h

