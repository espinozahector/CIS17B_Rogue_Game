#include "coinblast.h"

#include <QTimer>
#include <QGraphicsScene>

Coinblast::Coinblast(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/imgs/deps/coinexplosion.png"));
    //Size 50, 50

    //Set timer for despawn
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this,SLOT(despawn()));
    timer->start(1000);
}

void Coinblast::despawn(){
    scene()->removeItem(this);
    delete this;
}
