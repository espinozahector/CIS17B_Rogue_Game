#ifndef ENEMYDEBT_H
#define ENEMYDEBT_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "character.h"

class EnemyDebt :
        public QObject, public QGraphicsPixmapItem,
        public Character
{
    Q_OBJECT
private:
    int vel;
    int eExp;

public:
    EnemyDebt(int, QGraphicsItem *parent = 0);

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

public slots:
    void idle();
    void fire();
};

#endif // ENEMYDEBT_H
