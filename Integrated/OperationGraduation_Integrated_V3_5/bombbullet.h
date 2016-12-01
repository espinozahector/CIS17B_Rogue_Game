#ifndef BOMBBULLET_H
#define BOMBBULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class BombBullet :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BombBullet(QGraphicsItem *parent = 0);
public slots:
    void despawn();
};

#endif // BOMBBULLET_H
