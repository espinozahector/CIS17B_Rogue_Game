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
    void design(int,int,bool *);
    void setVal(int);
    int getVal() {return val;}

    void miniDesign();
    void miniMove(int,int);
private:
    int val;
public slots:
    void miniCurrent();
    void miniLast();
};

#endif // TILE_H
