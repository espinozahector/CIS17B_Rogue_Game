#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T16:25:19
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RogueGame
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    enemyfood.cpp \
    foodbullet.cpp \
    enemybomb.cpp \
    bombbullet.cpp \
    enemydebt.cpp \
    debtbullet.cpp \
    coinblast.cpp \
    character.cpp \
    inv.cpp \
    item.cpp \
    pjock.cpp \
    player.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    health.h \
    score.h \
    enemyfood.h \
    foodbullet.h \
    enemybomb.h \
    bombbullet.h \
    enemydebt.h \
    debtbullet.h \
    coinblast.h \
    character.h \
    inv.h \
    item.h \
    pjock.h \
    player.h

RESOURCES += \
    res.qrc
