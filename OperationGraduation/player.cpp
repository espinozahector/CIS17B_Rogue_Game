//User Libraries
#include "player.h"
//System and Qt Libraries
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set graphic
    setPixmap(QPixmap(":/images/snow.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //move the player left and right
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-10,y());
    }else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 940)
        setPos(x()+10,y());
    }
}
