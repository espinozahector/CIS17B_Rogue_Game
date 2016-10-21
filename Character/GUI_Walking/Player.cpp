
#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "Player.h"
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>

#include <QDebug>

Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //set inital position
    setPos(400,300);

    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_Front.png"));

    //checks if player is moving
    pMovement = false;

    //tracks player's leading foot
    footLeft = true;
    footRight = false;



}

void Player::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_A){

        if(!pMovement){
            movement();
            moveLeft();
        }

    }
    else if (event->key() == Qt::Key_D){

        if(!pMovement){
            movement();
            moveRight();
        }

    }
    else if (event->key() == Qt::Key_W){

        if(!pMovement){
            movement();
            moveUp();
        }
    }
    else if (event->key() == Qt::Key_S){

        if(!pMovement){
            movement();
            moveDown();
        }

    }
    else if (event->key() == Qt::Key_Space) {
        //attack
    }
}


void Player::moveRight()
{
    //after 120 seconds, sets pMovement to false
    QTimer::singleShot(120, this, SLOT(idle()));

    if (footLeft){

        QTimer::singleShot(120, this, SLOT(moveRight1()));
        QTimer::singleShot(0, this, SLOT(moveRight2()));

        //set next leading foot
        footLeft = false;
        footRight = true;

    }else if (footRight) {

         QTimer::singleShot(120, this, SLOT(moveRight1()));
         QTimer::singleShot(0, this, SLOT(moveRight3()));

         //sets next leading foot
         footRight = false;
         footLeft = true;
    }
}

void Player::moveRight1()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_LookingRight.png"));

}

void Player::moveRight2()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingRight_1.png"));
    setPos(x()+10,y());

}

void Player::moveRight3()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingRight_2.png"));
    setPos(x()+10,y());
}

void Player::moveLeft()
{

    //after 120 seconds, sets pMovement to false
    QTimer::singleShot(120, this, SLOT(idle()));

    if (footLeft){

        QTimer::singleShot(120, this, SLOT(moveLeft1()));
        QTimer::singleShot(0, this, SLOT(moveLeft2()));

        //sets next leading foot
        footLeft = false;
        footRight = true;

    } else if (footRight) {

         QTimer::singleShot(120, this, SLOT(moveLeft1()));
         QTimer::singleShot(0, this, SLOT(moveLeft3()));

         //sets next leading foot
         footRight = false;
         footLeft = true;

    }


}

void Player::moveLeft1()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_LookingLeft.png"));
}

void Player::moveLeft2()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingLeft_1.png"));
    setPos(x()-10,y());
}

void Player::moveLeft3()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingLeft_2.png"));
    setPos(x()-10,y());

}


void Player::moveUp()
{

    //after 120 seconds, sets pMovement to false
    QTimer::singleShot(120, this, SLOT(idle()));

    if (footLeft){

        QTimer::singleShot(120, this, SLOT(moveUp1()));
        QTimer::singleShot(0, this, SLOT(moveUp2()));

        //sets next leading foot
        footLeft = false;
        footRight = true;

    } else if (footRight) {

         QTimer::singleShot(120, this, SLOT(moveUp1()));
         QTimer::singleShot(0, this, SLOT(moveUp3()));

         //sets next leading foot
         footRight = false;
         footLeft = true;

    }
}

void Player::moveUp1()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_Back.png"));

}

void Player::moveUp2()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingBack_1.png"));
    setPos(x(),y()-10);

}

void Player::moveUp3()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingBack_2.png"));
    setPos(x(),y()-10);
}

void Player::moveDown()
{
    //set pDown false
    QTimer::singleShot(120, this, SLOT(idle()));

    if (footLeft){

        QTimer::singleShot(120, this, SLOT(moveDown1()));
        QTimer::singleShot(0, this, SLOT(moveDown2()));

        //sets next leading foot
        footLeft = false;
        footRight = true;

    } else if (footRight) {

         QTimer::singleShot(120, this, SLOT(moveDown1()));
         QTimer::singleShot(0, this, SLOT(moveDown3()));

         //sets next leading foot
         footRight = false;
         footLeft = true;

    }
}

void Player::moveDown1()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_Front.png"));

}

void Player::moveDown2()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingFront_1.png"));
    setPos(x(),y()+10);

}

void Player::moveDown3()
{
    //set graphic
    setPixmap(QPixmap(":/gfx/Programmer_WalkingFront_2.png"));
    setPos(x(),y()+10);
}

void Player::movement()
{
    pMovement = true;
}

void Player::idle()
{
    pMovement = false;
}


