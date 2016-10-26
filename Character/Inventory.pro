#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T11:36:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Inventory
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../../Desktop/shoe.gif \
    ../../Desktop/pants.jpg \
    ../../Desktop/weapon.jpg \
    ../../Desktop/helmet.png \
    ../../Desktop/shirt.jpeg

RESOURCES += \
    ../../Desktop/pictures.qrc
