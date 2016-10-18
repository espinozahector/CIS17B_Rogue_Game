#include "tile.h"

Tile::Tile(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
       //do nothing but create the tile
}

void Tile::move(int x, int y)
{
    this->setPos((x*60),(y*60));
}

void Tile::design(int x, int y)
{
    //Set the tile image

    //SETS the doors
    if(x == 7 && y == 0)
    {
        setPixmap(QPixmap(":/Map/images/map/Up_Door.jpg"));
    }
    else if(x == 7 && y == 8)
    {
        setPixmap(QPixmap(":/Map/images/map/Down_door.jpg"));
    }
    else if(x == 0 && y == 4)
    {
        setPixmap(QPixmap(":/Map/images/map/Left_door.jpg"));
    }
    else if(x == 14 && y ==4)
    {
        setPixmap(QPixmap(":/Map/images/map/Right_door.jpg"));
    }

    //SETS everything else
    else if(x == 0 || x == 14)
    {
        setPixmap(QPixmap(":/Map/images/map/side_wall.jpg"));
    }
    else if(y == 0 || y == 8)
    {
        setPixmap(QPixmap(":/Map/images/map/Wall.jpg"));
    }
    else if(val == 1)
    {
        setPixmap(QPixmap(":/Map/images/map/ClassFloor2.jpg"));
    }
    else if(val == 0)
    {
        setPixmap(QPixmap(":/Map/images/map/obstacle.png"));
    }
    else
    {
        setPixmap(QPixmap(":/Map/images/map/errorTile.png"));
    }
}

void Tile::setVal(int v)
{
    val = v;
}
