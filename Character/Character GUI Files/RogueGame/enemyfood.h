#ifndef ENEMYFOOD_H
#define ENEMYFOOD_H


#include <QGraphicsPixmapItem>
#include <QObject>

class EnemyFood :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int vel;

public:
    EnemyFood();
public slots:
    void idle();
    void fire();

};

#endif // ENEMYFOOD_H
