#ifndef FOODBULLET_H
#define FOODBULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Foodbullet :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Foodbullet(QGraphicsItem *parent =0);
public slots:
    void despawn();
};

#endif // FOODBULLET_H
