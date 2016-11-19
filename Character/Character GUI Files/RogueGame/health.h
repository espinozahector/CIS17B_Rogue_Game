#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
private:
    int hp;
public:
    Health(QGraphicsItem *parent = 0);

    //Health decrease and get
    void decHp();
    int getHp(){return hp;}
};

#endif // HEALTH_H
