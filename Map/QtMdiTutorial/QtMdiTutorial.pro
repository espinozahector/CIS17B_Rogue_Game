#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T15:37:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMdiTutorial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    childwindow.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    childwindow.h \
    mywidget.h

FORMS    += mainwindow.ui \
    mywidget.ui
