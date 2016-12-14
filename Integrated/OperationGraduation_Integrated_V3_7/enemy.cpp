#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <QList>
#include <typeinfo>

#include <QDebug>

#include "bullet.h"
#include "binarybullet.h"
#include "game.h"

extern Game *GAME;

Enemy::Enemy(int level, QGraphicsItem *parent) :
    QObject(), QGraphicsPixmapItem(parent), Character()
{
    //Set random position
    int randX = (rand()%610)+90;
    int randY = (rand()%250)+90;
    setPos(randX,randY);
    setZValue(9);


    //Draw enemy
    setPixmap(QPixmap(":/Character/images/characters/enemyexam.png"));


    //Set speed
    vel = 6;

    //Set stats
    setName("Exam Fiend");
    setHpMx(30+(20*level/3));
    setHp(getHpMx());
    setDmg(8+(8*level/3));
    setAC(10+(5*level/3));
    setCrit(5+(5*level/3));
    setExp(8 + (10*level/3));

    //Generate inventory
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
Enemy::~Enemy(){
}

void Enemy::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int Enemy::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int Enemy::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 2;

    //Calculates target damage
    return target.getHit(dmg);
}
/*
Item Enemy::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}
*/

void Enemy::idle(){
    int direction = rand()% 6;

    for(int i = 0; i < 3; i++){
        if(direction == 0){

            //Move enemy up
            if(y() - 40 > 0)
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

void Enemy::fire(){
    std::vector<Bullet*> bullets(8);

    for(int i = 0; i < 8; i++){
        bullets[i] = new Bullet();
        bullets[i]->setDir(i);
        bullets[i]->setPos(x()+ 50, y()+50);
        bullets[i]->setZValue(1);
        scene()->addItem(bullets[i]);
    }
}

void Enemy::checkCollision(){
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

