#include "binarybullet.h"

#include <QDebug>

BinaryBullet::BinaryBullet(QGraphicsItem *parent)
{

    binaryBullet = new QPixmap(":/Character/images/characters/binaryBullet.png");
    QPixmap bullet;

    int frame = binaryRand();

    if (frame <= 5){
        bullet = binaryBullet->copy(22, 16, 8, 24);
    }
    else if (frame > 5)
    {
        bullet = binaryBullet->copy(80, 16, 18, 24);
    }

    setPixmap(bullet);

    this->timer = new QTimer;
    timer->setInterval(20);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

int BinaryBullet::binaryRand()
{
    int j = 1 + (int) (10.0 * (rand() / (RAND_MAX + 1.0)));

    return j;
}

void BinaryBullet::setDir(int direct)
{
    dir = direct;
}

void BinaryBullet::move()
{

    switch (dir)
    {
        case 1:
            {
                setPos(x()-10,y());
                break;
            }

        case 2:
            {

                setPos(x()+10,y());
                break;
            }

        case 3:
            {
                setPos(x(),y()-10);
                break;
            }

        case 4:
            {
                setPos(x(),y()+10);
                break;
            }
    default:
        break;

    }

    //if item moves offscreen
    if(pos().y()-25 < 0 || pos().y() + 50 > 540
            || pos().x() - 25 < 0 || pos().x()+40 > 850){
        delete this;
    }
}


