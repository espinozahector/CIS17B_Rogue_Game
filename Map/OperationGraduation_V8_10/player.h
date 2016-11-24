#ifndef PLAYER_H
#define PLAYER_H

//System and Qt Libraries
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
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
    int playerx;    // used for player location on the map ! the room
    int playery;    // used for player location on the map ! the room
    int lvlCnt;     // Counts the levels completed
public:
    Player(Map *);
    Map *temp;
    bool isBoss2;

    //returns true if player is moving
    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;

    //returns true if player is attacking
    bool isAttacking;

    //holds speed
    int velocity;

    QTimer *timer;

    QPixmap *csMajor;

    //holds values to move to the next frame
    int spriteCoordLeftRight;
    int spriteCoordUpDown;

    void nextFrame(char direction);
    void restartFrame();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    int getMapX() {return playerx;}
    int getMapY() {return playery;}
    void setMapX(int x) {playerx = x;}
    void setMapY(int y) {playery = y;}
    void setLvlCnt(int val) {lvlCnt = val;}
    int getLvlCnt() {return lvlCnt;}
    void trapDoor(int,int);
    void setMap(Map*);

signals:
    //void update();
    void enterDoor();       // New Room
    void eatTaco(int,int);  // MiniMap
    void newLevel();        // New Level

public slots:
    void timerEvent(); //handles player movement
};

#endif // PLAYER_H
