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
};

#endif // ENEMYDEBT_H
