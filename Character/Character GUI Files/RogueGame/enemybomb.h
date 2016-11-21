#ifndef ENEMYBOMB_H
#define ENEMYBOMB_H

#include <QGraphicsPixmapItem>
#include <QObject>

class EnemyBomb :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int vel;

public:
    EnemyBomb();
public slots:
    void idle();
    void fire();
};

#endif // ENEMYBOMB_H
