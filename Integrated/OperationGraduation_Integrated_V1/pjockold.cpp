#include "pjockold.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <ctime>
#include <QList>
#include <typeinfo>

//includes debugger
#include <QDebug>

#include "bullet.h"
#include "coinblast.h"
#include "bombbullet.h"
#include "foodbullet.h"

#include "enemy.h"
#include "enemyfood.h"
#include "enemybomb.h"
#include "enemydebt.h"

#include "game.h"

extern Game *GAME;

PJock::PJock(string name, QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem(parent),
    Player(name, 110, 10, 7, 2)
{
    //Set player image
    setPixmap(QPixmap(":/imgs/deps/player.png"));

    //Set velocity
    vel = 10;

    stun = false;

    //timer for checking collision
    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(checkCollision()));
    timer1->start(10);
}


void PJock::keyPressEvent(QKeyEvent *event){

    //Reads key
    if(event->key() == Qt::Key_A){
        if(pos().x() > 0)
            setPos(x()-vel, y());
    }
    else if(event->key() == Qt::Key_D){
        if(pos().x()+100 < 800 )
            setPos(x()+vel, y());
    }
    else if(event->key() == Qt::Key_W){
        if(pos().y() > 0)
            setPos(x(), y()-vel);
    }
    else if(event->key() == Qt::Key_S){
        if(pos().y()+100 < 800)
            setPos(x(), y()+vel);
    }

    if(event->key() == Qt::Key_Space){
        /*
        Bullet *bullet = new Bullet();
        //scene() returns pointer to scene
        bullet->setPos(x()+50, y());
        scene()->addItem(bullet);

        //Play bullet
        //If the bullet is already playing
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            //Rewind sound
            bulletsound->setPosition(0);
        }
        //Else if it's paused
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            //Play normally
            bulletsound->play();
        }
        */
    }

}


bool PJock::grabItem(Item item){
    bool flag = false;

    //If item isn't blank
    if(item.getID() > -1){
        //Appened specific item name
        item.setName(item.getName()+" "
                     +genName(item.getID()));
        //Add item to inventory
        getInv()->setItem(item, item.getID());
        //Set item stats
        equip(item.getID());
        //Flag item success
        flag = true;
    }

    //Return flag
    return flag;
}

int PJock::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int PJock::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

string PJock::genName(int slot){
    string name;
    switch(slot){
        case 0:
            name = "Helmet";
            break;
        case 1:
            name = "Padded Jersey";
            break;
        case 2:
            name = "Thigh pads";
            break;
        case 3:
            name = "Cleats";
            break;
        case 4:
            name = "Bat";
            break;
        case 5:
            name = "Tackle Dummy";
            break;
        default:
            name = "";
            break;
    }
    return name;
}


void PJock::checkCollision(){
    //Check for collision with player
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //Goes through all colliding items
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        //If collided with essay enemy
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with bomb
        if(typeid(*(colliding_items[i])) == typeid(EnemyBomb)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with debt
        if(typeid(*(colliding_items[i])) == typeid(EnemyDebt)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with food
        if(typeid(*(colliding_items[i])) == typeid(EnemyFood)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with essay bullet
        if(typeid(*(colliding_items[i])) == typeid(Bullet)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }

            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }

        //If colliding with explosion
        if(typeid(*(colliding_items[i])) == typeid(BombBullet)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with coin blast
        if(typeid(*(colliding_items[i])) == typeid(Coinblast)){

            GAME->hp->decHp();

            if(GAME->hp->getHp() <= 0){
                scene()->removeItem(this);
                delete this;
            }
        }

        //If collided with food slime
        if(typeid(*(colliding_items[i])) == typeid(Foodbullet)){
            vel = 5;
            qDebug() <<"Vel: "<<vel;
        }
        else{
            vel = 10;
            qDebug() <<"Vel: "<<vel;
        }

    }

}

