#ifndef TILE_H
#define TILE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Tile: public QGraphicsPixmapItem{
public:
    Tile(QGraphicsItem *parent=0);
    void move(int,int);
    void design(int,int);
    void setVal(int);
private:
    int val;
};


#endif // TILE_H
