TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    patient.cpp \
    csv.cpp \
    ctscan.cpp \
    patientfactory.cpp \
    util.cpp \
    writer.cpp

HEADERS += \
    patient.h \
    csv.h \
    ctscan.h \
    patientfactory.h \
    util.h \
    writer.h
