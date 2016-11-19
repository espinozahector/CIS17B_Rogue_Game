#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo> //Enables object type info
#include <QDebug>

#include "enemy.h"
#include "game.h"

extern Game* GAME; //Includes external global constants

Bullet::Bullet(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/imgs/deps/exambullet.png"));

    //Set bullet direction
    dir = 0;

    //Connect
    //Timer item counts down and sends signal whenever it reaches 0
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this, SLOT(move()));

    //Sets timer time to 50ms
    timer->start(50);
}

void Bullet::setDir(int direction){
    if(direction < 8 && direction > -1){
        dir = direction;
    }
}

void Bullet::move(){
    //Check collision with player
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //Checks all colliding items
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        //If the colliding item is an enemy
        if(typeid(*(colliding_items[i])) == typeid(Player)){

            //Decrease health
            GAME->hp->decHp();

            //If hp < 0
            if(GAME->hp->getHp() <= 0){
                //Remove & delete player
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }


            //Remove & delete bullet
            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    //Check set direction for bullet
    switch(dir){
        //Move up
        case 0:
            setPos(x(),y()-10);
            break;
        //Move top right
        case 1:
            setPos(x()+10,y()-10);
            break;
        //Move right
        case 2:
            setPos(x()+10,y());
            break;
        //Move bot right
        case 3:
            setPos(x()+10,y()+10);
            break;
        //Move bottom
        case 4:
            setPos(x(),y()+10);
            break;
        //Move bot left
        case 5:
            setPos(x()-10,y()+10);
            break;
        //Move left
        case 6:
            setPos(x()-10,y());
            break;
        //Move top left
        case 7:
            setPos(x()-10,y()-10);
            break;

    }

    //if item moves offscren
    if(pos().y()-25 < 0 || pos().y() + 50 > 600
            || pos().x() - 25 < 0 || pos().x()+50 > 800){
        //Remove item from scene before deleting
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Bullet deleted.";

    }
}

