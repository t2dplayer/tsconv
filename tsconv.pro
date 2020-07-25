TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += fmt\include
INCLUDEPATH += igloo
LIBS += -L"fmt\build" -lfmt

SOURCES += \
        date.cpp \
        main.cpp

HEADERS += \
    date.h
