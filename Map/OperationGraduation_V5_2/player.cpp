//User Libraries
#include "player.h"
//System and Qt Libraries
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/Character/images/characters/characterBase.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //move the player left and right
    if(event->key() == Qt::Key_A){
        if(pos().x() > 70)
            setPos(x()-10,y());
    }else if (event->key() == Qt::Key_D){
        if (pos().x() + 100 < 900)
        setPos(x()+10,y());
    }else if (event->key() == Qt::Key_W){
        if (pos().y() > 209)
        setPos(x(),y()-10);
    }else if (event->key() == Qt::Key_S){
        if (pos().y() + 100 < 700)
        setPos(x(),y()+10);
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
