TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_filesystem -lboost_system

SOURCES += main.cpp \
    gnuplotscriptfactory.cpp \
    plotselector.cpp

HEADERS += \
    gnuplotscriptfactory.h \
    plotselector.h
