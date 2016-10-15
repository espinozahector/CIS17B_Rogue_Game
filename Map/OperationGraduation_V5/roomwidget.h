#ifndef ROOMWIDGET_H
#define ROOMWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "map.h"
#include "tile.h"

class RoomWidget : QGraphicsScene
{
private:
    int rows;
    int cols;
    QWidget *newRoom;
public:
    RoomWidget(QWidget *parent = 0);
};

#endif // ROOMWIDGET_H
