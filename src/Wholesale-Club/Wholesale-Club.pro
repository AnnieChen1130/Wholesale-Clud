TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    club.cpp \
    item.cpp \
    wholesale.cpp \
    mainwindow.cpp

HEADERS += \
    club.h \
    item.h \
    linkedlist.h \
    wholesale.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
