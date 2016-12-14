#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem> //Rectangle item
#include <QGraphicsPixmapItem>
#include <QObject> //allows signals and slots

#include "character.h"

class Enemy :
        public QObject, public QGraphicsPixmapItem,
        public Character
{
    Q_OBJECT
private:
    int vel;
    int eExp;

public:
    Enemy(int, QGraphicsItem *parent = 0);
    ~Enemy();

    //Sets exp worth(exp)
    //Accept values 0-999
    void setExp(int);
    int getExp(){return eExp;}

    //Enemy attack functions
    //Calc/return dmg on character
    int attack1(Character&);
    int attack2(Character&);

    //Generates a random number and returns an item based
    //on the result
    //Item drop();
signals:
    void death();

public slots:
    void idle();
    void fire();
    void checkCollision();
};

#endif // ENEMY_H
