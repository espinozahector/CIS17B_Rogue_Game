#include "foodbullet.h"

#include <QTimer>
#include <QGraphicsScene>

Foodbullet::Foodbullet(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/Character/images/characters/foodbullet.png"));
    //Size 50, 50

    //Set timer for despawn
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this,SLOT(despawn()));
    timer->start(3000);
}

void Foodbullet::despawn(){
    scene()->removeItem(this);
    delete this;
    return;
}
