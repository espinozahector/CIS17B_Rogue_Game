#include "enemybomb.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

#include <cstdlib>
#include <ctime>

#include "bombbullet.h"

EnemyBomb::EnemyBomb(int level, QGraphicsItem *parent) :
    QObject(), QGraphicsPixmapItem(parent), Character()
{
    //Set random position
    int randX = (rand()%610)+90;
    int randY = (rand()%250)+90;
    setPos(randX,randY);
    setZValue(9);

    //Draw enemy
    setPixmap(QPixmap(":/Character/images/characters/enemyboomdate.png"));


    //Set speed
    vel = 6;

    //Set stats & inv
    setName("Doom Date");
    setHpMx(10+(10*level/3));
    setHp(getHpMx());
    setDmg(20+(20*level/3));
    setAC(1+(2*level/3));
    setCrit(10+(5*level/3));
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
    timer2->start(3000);
}


void EnemyBomb::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int EnemyBomb::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int EnemyBomb::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}
/*
Item EnemyBomb::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}
*/

void EnemyBomb::idle(){
    int direction = rand()%6;

    for(int i = 0; i < 5; i++){
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

void EnemyBomb::fire(){
    BombBullet *explosion = new BombBullet();
    explosion->setPos(x(), y());
    scene()->addItem(explosion);
    scene()->removeItem(this);
    delete this;
    return;
}
