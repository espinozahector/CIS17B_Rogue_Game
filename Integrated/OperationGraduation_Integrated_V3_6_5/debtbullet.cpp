#include "debtbullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "coinblast.h"

DebtBullet::DebtBullet(QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/Character/images/characters/debtbullet.png"));
    //Size 50, 50

    //Set timer for despawn
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this,SLOT(explode()));
    timer->start(4000);



}

void DebtBullet::explode(){
    Coinblast *blast = new Coinblast();
    blast->setPos(x()-10, y()-10);
    blast->setZValue(1);
    scene()->addItem(blast);

    scene()->removeItem(this);
    delete this;
}
