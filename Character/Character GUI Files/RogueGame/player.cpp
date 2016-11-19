#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <ctime>

//includes debugger
#include <QDebug>

#include "bullet.h"
#include "enemy.h"
#include "enemyfood.h"
#include "enemybomb.h"
#include "enemydebt.h"

Player::Player(QGraphicsItem* parent):
    QGraphicsPixmapItem(parent)
{
    //Set player image
    setPixmap(QPixmap(":/imgs/deps/player.png"));

    //Set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/dep/pew.mp3"));

}



void Player::keyPressEvent(QKeyEvent *event){

    //Reads key
    if(event->key() == Qt::Key_A){
        if(pos().x() > 0)
            setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_D){
        if(pos().x()+100 < 800 )
            setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_W){
        if(pos().y() > 0)
            setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_S){
        if(pos().y()+100 < 800)
            setPos(x(), y()+10);
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

void Player::spawn(){
    //Create enemies
    Enemy *enemy = new Enemy();
    EnemyFood *enemy2 = new EnemyFood();
    EnemyBomb *enemy3 = new EnemyBomb();
    EnemyDebt *enemy4 = new EnemyDebt();

    scene()->addItem(enemy);
    scene()->addItem(enemy2);
    scene()->addItem(enemy3);
    scene()->addItem(enemy4);
}
