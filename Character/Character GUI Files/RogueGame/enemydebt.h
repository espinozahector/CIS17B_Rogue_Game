#ifndef ENEMYDEBT_H
#define ENEMYDEBT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class EnemyDebt :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int vel;

public:
    EnemyDebt();

public slots:
    void idle();
    void fire();
};

#endif // ENEMYDEBT_H
