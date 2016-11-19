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

EnemyFood::EnemyFood():
    QObject(), QGraphicsPixmapItem()
{
    //Set random position
    int randX = rand() % 700;
    int randY = rand() % 500;
    setPos(randX,randY);

    //Draw enemy
    setPixmap(QPixmap(":/imgs/deps/enemyfood.png"));

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
    timer2->start(200);

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
