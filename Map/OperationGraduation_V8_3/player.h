#ifndef PLAYER_H
#define PLAYER_H

//System and Qt Libraries
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>
using namespace std;

#include "map.h"

/*
 * Objective: Move player to next room upon entering a door
 *
 * player -> which door is he entering? How do we know?
 */

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int playerx; //used for player location on the map ! the room
    int playery; //used for player location on the map ! the room
public:
    Player(Map *);
    void keyPressEvent(QKeyEvent *event);
    int getMapX() {return playerx;}
    int getMapY() {return playery;}
    Map *temp;

signals:
    //void update();
    void enterDoor();
    void eatTaco(int,int);
public slots:
};

#endif // PLAYER_H
