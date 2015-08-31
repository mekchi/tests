TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    line.cpp

LIBS += -lSDL2

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    line.h

