QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = WholeSale-Club
TEMPLATE = app

SOURCES += main.cpp \
        mainwindow.cpp \
    club.cpp \
    item.cpp \
    wholesale.cpp \
    date.cpp


HEADERS += mainwindow.h \
    club.h \
    item.h \
    linkedlist.h \
    wholesale.h \
    date.h


FORMS   += mainwindow.ui
