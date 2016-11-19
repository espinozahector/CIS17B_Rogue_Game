#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>

#include <QDebug>

#include "bullet.h"
#include "game.h"

extern Game *GAME;

Enemy::Enemy() :
    QObject(), QGraphicsPixmapItem()
{
    //Set random position
    int randX = rand() % 700;
    int randY = rand() % 500;
    setPos(randX,randY);

    //Draw enemy
    setPixmap(QPixmap(":/imgs/deps/enemyexam.png"));

    //Set speed
    vel = 6;


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

void Enemy::idle(){


    int direction = rand()%6;

    for(int i = 0; i < 3; i++){
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

void Enemy::fire(){
    std::vector<Bullet*> bullets(8);

    for(int i = 0; i < 8; i++){
        bullets[i] = new Bullet();
        bullets[i]->setDir(i);
        bullets[i]->setPos(x()+ 50, y()+50);
        scene()->addItem(bullets[i]);
    }

}
