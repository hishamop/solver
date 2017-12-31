TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS =  -w -I /usr/include/coin
LIBS = -lipopt


SOURCES += main.cpp \
    cmodel.cpp \
    cfileio.cpp \
    cnlp.cpp

HEADERS += \
    cmodel.h \
    cfileio.h \
    cnlp.h \
    utility/auxil.h
