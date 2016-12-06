#ifndef DEBTBULLET_H
#define DEBTBULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class DebtBullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    DebtBullet(QGraphicsItem * parent = 0);
public slots:
    void explode();
};

#endif // DEBTBULLET_H
