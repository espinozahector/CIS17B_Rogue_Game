//User Libraries
#include "player.h"
//System and Qt Libraries
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/Character/images/characters/characterBase.png"));
    playerx = 4;
    playery = 4;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //move the player left
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
    {
        if(pos().x() <=70 && pos().x() > 20 && pos().y() == 410)
        {
            setPos(x()-10,y());
        }
        else if(pos().x() > 70)
        {
            setPos(x()-10,y());
        }
    }
    //Move the player Right
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
    {
        if(pos().x() >= 800 && pos().x() < 850 && pos().y() == 410)
        {
            setPos(x()+10,y());
        }
        else if(pos().x() + 100 < 900)
        {
            setPos(x()+10,y());
        }
    }
    //Move the player up
    else if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
    {
        if(pos().x() == 440 && pos().y() <= 200 && pos().y() > 180)
        {
            setPos(x(),y()-10);
        }
        else if(pos().y() > 209)
        {
            setPos(x(),y()-10);
        }
    }
    //Move the player down
    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
    {
        if(pos().x() == 440 && pos().y() >= 600 && pos().y() < 650)
        {
            setPos(x(),y()+10);
        }
        if(pos().y() + 100 < 700)
        {
            setPos(x(),y()+10);
        }
    }
}

//void Player::keyPressEvent(QKeyEvent *event)
//{
//    const int FPS = 60;

//    // move player left
//    if (event->key() == Qt::Key_A) {
//        if (direction == directions::right) {
//            // face character left
//            setTransform(QTransform::fromScale(-1, 1));
//            direction = directions::left;
//        }

//        if (!moveTimer->isActive()) {
//            moveTimer->start(1000/FPS);
//        }
//    }
//    // move player right
//    else if (event->key() == Qt::Key_D) {
//        if (direction == directions::left) {
//            // face character right
//            setTransform(QTransform::fromScale(1, 1));
//            direction = directions::right;
//        }

//        if (!moveTimer->isActive()) {
//            moveTimer->start(1000/FPS);
//        }
//    }
//}

//void Player::keyReleaseEvent(QKeyEvent *event)
//{
//    // stop player moving left or right
//    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D) {

//        if (moveTimer->isActive()) {
//            moveTimer->stop();
//        }
//    }
//}

//void Character::move()
//{
//    const double DISTANCE_MOVED_PER_FRAME = 1.0;

//    if (direction == directions::right) {
//        // player wants to move right
//        setPos(x() + DISTANCE_MOVED_PER_FRAME,y());
//    }
//    else {
//        // player wants to move left
//        setPos(x() - DISTANCE_MOVED_PER_FRAME,y());
//    }
//}
