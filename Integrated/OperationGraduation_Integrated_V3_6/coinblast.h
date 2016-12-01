#ifndef COINBLAST_H
#define COINBLAST_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Coinblast :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Coinblast(QGraphicsItem * parent = 0);
public slots:
    void despawn();
};

#endif // COINBLAST_H
