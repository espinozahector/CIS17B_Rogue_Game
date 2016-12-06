#-------------------------------------------------
#
# Project created by QtCreator 2016-10-07T17:48:54
#
#-------------------------------------------------

QT       += core \
            core gui \
            multimedia \
            sql \
            network

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
    tile.cpp \
    splash.cpp \
    roomchild.cpp \
    mainwindow.cpp \
    loginchild.cpp \
    logindia.cpp \
    statchild.cpp \
    minimapchild.cpp \
    registerchild.cpp \
    registeruser.cpp \
    mini.cpp \
    character.cpp \
    player.cpp \
    bullet.cpp \
    coinblast.cpp \
    bombbullet.cpp \
    foodbullet.cpp \
    enemy.cpp \
    enemyfood.cpp \
    enemybomb.cpp \
    enemydebt.cpp \
    debtbullet.cpp \
    binarybullet.cpp

HEADERS  += \
    game.h \
    map.h \
    room.h \
    level.h \
    cols.h \
    row.h \
    tile.h \
    splash.h \
    roomchild.h \
    mainwindow.h \
    loginchild.h \
    logindia.h \
    statchild.h \
    minimapchild.h \
    connection.h \
    registerchild.h \
    registeruser.h \
    mini.h \
    character.h \
    player.h \
    bullet.h \
    coinblast.h \
    bombbullet.h \
    foodbullet.h \
    enemy.h \
    enemyfood.h \
    enemybomb.h \
    enemydebt.h \
    debtbullet.h \
    binarybullet.h

FORMS    += \
    mainwindow.ui \
    statchild.ui

RESOURCES += \
    res.qrc
