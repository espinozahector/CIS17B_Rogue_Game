#include "enemyfood.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

#include <cstdlib>
#include <ctime>


#include <QDebug>
#include "game.h"
#include "foodbullet.h"

extern Game *GAME;

EnemyFood::EnemyFood(int level, QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent), Character()
{
    //Set random position
    int randX = rand() % 700;
    int randY = rand() % 500;
    setPos(randX,randY);

    //Draw enemy
    setPixmap(QPixmap(":/imgs/deps/enemyfood.png"));

    //Set speed
    vel = 6;

    //Set stats
    setName("Rotted Food");
    setHpMx(40+(30*level/3));
    setHp(getHpMx());
    setDmg(10+(10*level/3));
    setAC(0+(2*level/3));
    setCrit(5+(5*level/3));
    setExp(10 + (10*level/3));

    createInv(10);
    getInv()->genInv(level);


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
    timer2->start(200);

}


void EnemyFood::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int EnemyFood::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int EnemyFood::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

Item EnemyFood::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}


void EnemyFood::idle(){


    int direction = rand()%6;

    for(int i = 0; i < 5; i++){
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

void EnemyFood::fire(){
    Foodbullet *bullet = new Foodbullet();
    bullet->setPos(x()+50, y()+50);
    bullet->setZValue(-1); //Set behind object
    scene()->addItem(bullet);
}
