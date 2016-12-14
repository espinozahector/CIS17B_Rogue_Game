#include "enemydebt.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <QList>
#include <typeinfo>
#include <QDebug>

#include "debtbullet.h"
#include "binarybullet.h"

EnemyDebt::EnemyDebt(int level, QGraphicsItem *parent) :
    QObject(), QGraphicsPixmapItem(parent), Character()
{
    //Set random position
    int randX = (rand()%610)+90;
    int randY = (rand()%250)+90;
    setPos(randX,randY);
    setZValue(9);

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
    QTimer *timer3 = new QTimer(this);

    //Connect timers
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(idle()));
    connect(timer2, SIGNAL(timeout()),
            this, SLOT(fire()));
    connect(timer3, SIGNAL(timeout()),
            this, SLOT(checkCollision()));

    timer1->start(200);

    int bullettimer = (rand()%1000)+1500;
    timer2->start(bullettimer);

    timer3->start(10);
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
            if(y()-40 > 0)
                setPos(x(), y()-vel);
        }
        else if(direction == 1){
            //Move enemy down
            if(y()+150 < 530)
                setPos(x(), y()+vel);
        }
        else if(direction == 2){
            //Move enemy left
            if(x()-55 > 0)
                setPos(x()-vel, y());
        }
        else if(direction == 3){
            //Move enemy right
            if(x()+150 < 895)
                setPos(x()+vel, y());
        }
    }
}

void EnemyDebt::fire(){
    DebtBullet *coin = new DebtBullet();
    coin->setPos(x()+20,y()+100);
    coin->setZValue(1);
    scene()->addItem(coin);
}

void EnemyDebt::checkCollision(){
    //Check for collision with player
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //Goes through all colliding items
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        //If collided with essay enemy
        if(typeid(*(colliding_items[i])) == typeid(BinaryBullet)){
            //qDebug() <<"Enemy collision detected.";
            getHit(10);
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];

            if(this->isDead()){
                emit death();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
