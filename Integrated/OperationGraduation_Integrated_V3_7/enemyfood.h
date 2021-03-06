#ifndef ENEMYFOOD_H
#define ENEMYFOOD_H


#include <QGraphicsPixmapItem>
#include <QObject>

#include "character.h"

class EnemyFood :
        public QObject, public QGraphicsPixmapItem,
        public Character
{
    Q_OBJECT
private:
    int vel;
    int eExp;

public:
    EnemyFood(int, QGraphicsItem *parent = 0);

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

#endif // ENEMYFOOD_H
