#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem> //Rectangle item
#include <QGraphicsPixmapItem>
#include <QObject> //allows signals and slots

class Enemy :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    int vel;
public:
    Enemy();

public slots:
    void idle();
    void fire();

};

#endif // ENEMY_H
