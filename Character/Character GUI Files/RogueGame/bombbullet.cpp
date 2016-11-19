#include "bombbullet.h"

#include <QTimer>
#include <QGraphicsScene>

BombBullet::BombBullet(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/imgs/deps/boombullet2.png"));
    //Size 50, 50

    //Set timer for despawn
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this,SLOT(despawn()));
    timer->start(1000);
}

void BombBullet::despawn(){
    scene()->removeItem(this);
    delete this;
    return;
}
