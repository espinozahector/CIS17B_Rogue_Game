#include "enemydebt.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

#include <cstdlib>
#include <ctime>
#include "debtbullet.h"

#include <QDebug>

EnemyDebt::EnemyDebt(int level, QGraphicsItem *parent) :
    QObject(), QGraphicsPixmapItem(parent), Character()
{
    //Set random position
    int randX = rand() % 700;
    int randY = rand() % 500;
    setPos(randX,randY);

    //Draw enemy
    setPixmap(QPixmap(":/Character/images/characters/enemydebt.png"));

    //Set speed
    vel = 2;

    //Set stats
    setName("Debt Ghost");
    setHpMx(20+(20*level/3));
    setHp(getHpMx());
    setDmg(10+(5*level/3));
    setAC(2+(2*level/3));
    setCrit(5+(5*level/3));
    setExp(5 + (10*level/3));

    //createInv(10);
    //getInv()->genInv(level);


    //Create timers
    //Movement timer
    QTimer *timer1 = new QTimer(this);
    //Attack timer
    QTimer *timer2 = new QTimer(this);

    //Connect timers
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(idle()));
    connect(timer2, SIGNAL(timeout()),
            this, SLOT(fire()));


    timer1->start(200);
    timer2->start(2000);

}


void EnemyDebt::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int EnemyDebt::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int EnemyDebt::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}
/*
Item EnemyDebt::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}
*/

void EnemyDebt::idle(){
    int direction = rand()%6;

    for(int i = 0; i < 10; i++){
        if(direction == 0){

            //Move enemy up
            if(y()-50 > 0)
                setPos(x(), y()-vel);
        }
        else if(direction == 1){
            //Move enemy down
            if(y()+150 < 600)
                setPos(x(), y()+vel);
        }
        else if(direction == 2){
            //Move enemy left
            if(x()-50 > 0)
                setPos(x()-vel, y());
        }
        else if(direction == 3){
            //Move enemy right
            if(x()+150 < 800)
                setPos(x()+vel, y());
        }
    }
}

void EnemyDebt::fire(){
    DebtBullet *coin = new DebtBullet();
    coin->setPos(x()+20,y()+100);
    coin->setZValue(-1);
    scene()->addItem(coin);
}
