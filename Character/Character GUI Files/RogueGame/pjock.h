#ifndef PJOCK_H
#define PJOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QTimer>

#include "player.h"

class PJock:
        public QObject, public QGraphicsPixmapItem,
        public Player
{
    Q_OBJECT
private:
    //String for player class
    const string PJOB = "Jock";
    //Name generator for items
    string genName(int);

    int vel;
    bool stun;

public:
    PJock(string, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);

    //Returns class name
    string getClass(){return PJOB;}

    //Sets item into the inventory
    bool grabItem(Item);

    //Player attack functions
    int attack1(Character&);
    int attack2(Character&);

public slots:
    void checkCollision();
};

#endif // PJOCK_H
