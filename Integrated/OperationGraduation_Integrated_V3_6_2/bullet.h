#ifndef BULLET_H
#define BULLET_H

//#include <QGraphicsRectItem>
//Change to graphic item
#include <QGraphicsPixmapItem>
#include <QObject> //allows signals and slots

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int dir; //direction for bullet
public:
    Bullet(QGraphicsItem *parent =0);
    void setDir(int);

public slots:
    void move();

};

#endif // BULLET_H
