//User Libraries
#include "player.h"
//System and Qt Libraries
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/images/characterBase.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //move the player left and right
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 60)
            setPos(x()-10,y());
    }else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 905)
        setPos(x()+10,y());
    }else if (event->key() == Qt::Key_Up){
        if (pos().y() > 60)
        setPos(x(),y()-10);
    }else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 460)
        setPos(x(),y()+10);
    }
}
