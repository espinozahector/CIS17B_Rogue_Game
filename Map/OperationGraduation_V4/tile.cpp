#include "tile.h"

Tile::Tile(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
       //do nothing but create the tile
}

void Tile::move(int x, int y)
{
    this->setPos((x*60) + 11,(y*60) + 169);
}

void Tile::design(int x, int y)
{
    //Set the tile image

    //SETS the doors
    if(x == 7 && y == 0)
    {
        setPixmap(QPixmap(":/tiles/Up_Door.jpg"));
    }
    else if(x == 7 && y == 8)
    {
        setPixmap(QPixmap(":/tiles/Down_door.jpg"));
    }
    else if(x == 0 && y == 4)
    {
        setPixmap(QPixmap(":/tiles/Left_door.jpg"));
    }
    else if(x == 15 && y ==4)
    {
        setPixmap(QPixmap(":/tiles/Right_door.jpg"));
    }

    //SETS everything else
    else if(x == 0 || x == 15)
    {
        setPixmap(QPixmap(":/tiles/side_wall.jpg"));
    }
    else if(y == 0 || y == 8)
    {
        setPixmap(QPixmap(":/tiles/Wall.jpg"));
    }
    else if(val == 1)
    {
        setPixmap(QPixmap(":/tiles/ClassFloor2.jpg"));
    }
    else if(val == 0)
    {
        setPixmap(QPixmap(":/tiles/obstacle.png"));
    }
    else
    {
        setPixmap(QPixmap(":/tiles/errorTile.png"));
    }
}

void Tile::setVal(int v)
{
    val = v;
}
