#-------------------------------------------------
#
# Project created by QtCreator 2016-10-07T17:48:54
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OperationGraduation
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    map.cpp \
    room.cpp \
    level.cpp \
    cols.cpp \
    row.cpp \
    player.cpp \
    tile.cpp

HEADERS  += \
    game.h \
    map.h \
    room.h \
    level.h \
    cols.h \
    row.h \
    player.h \
    tile.h

FORMS    +=

RESOURCES += \
    res.qrc
