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
    player.cpp \
    enemyfood.cpp \
    foodbullet.cpp \
    enemybomb.cpp \
    bombbullet.cpp \
    enemydebt.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    health.h \
    score.h \
    player.h \
    enemyfood.h \
    foodbullet.h \
    enemybomb.h \
    bombbullet.h \
    enemydebt.h

RESOURCES += \
    res.qrc
