#ifndef BINARYBULLET_H
#define BINARYBULLET_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <ctime>

class BinaryBullet :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BinaryBullet(QGraphicsItem *parent = 0);

    //direction of bullet
    int dir;

    //hold picture of bullets
    QPixmap *binaryBullet;

    //starts movement of bullet
    QTimer *timer;

    int binaryRand();           //randomly chooses one or zero
    void setDir(int direct);    //sets direction

public slots:
    void move();


};

#endif // BINARYBULLET_H

