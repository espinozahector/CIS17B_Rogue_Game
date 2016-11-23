#include "tile.h"

Tile::Tile(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //Nothing to see here
}

void Tile::move(int x, int y)
{
    this->setPos((x*60),(y*60));
}

void Tile::design(int x, int y, bool *a)
{
    //Set the tile image

    //SETS the doors
    if(x == 7 && y == 0 && a[0])
    {
        setPixmap(QPixmap(":/Map/images/map/classDoor_top.png"));
        this->setScale(0.25);
    }
    else if(x == 7 && y == 8 && a[2])
    {
        setPixmap(QPixmap(":/Map/images/map/classDoor_bot.png"));
        this->setScale(0.25);
    }
    else if(x == 0 && y == 4 && a[3])
    {
        setPixmap(QPixmap(":/Map/images/map/classDoor_left.png"));
        this->setScale(0.25);
    }
    else if(x == 14 && y ==4 && a[1])
    {
        setPixmap(QPixmap(":/Map/images/map/classDoor_right.png"));
        this->setScale(0.25);
    }

    //SETS WALLS
    else if(x == 0)
    {
        setPixmap(QPixmap(":/Map/images/map/classWall_left.png"));
        this->setScale(0.25);
    }
    else if(x == 14)
    {
        setPixmap(QPixmap(":/Map/images/map/classWall_right.png"));
        this->setScale(0.25);
    }
    else if(y == 0)
    {
        setPixmap(QPixmap(":/Map/images/map/classWall_top.png"));
        this->setScale(0.25);
    }
    else if(y == 8)
    {
        setPixmap(QPixmap(":/Map/images/map/classWall_bot.png"));
        this->setScale(0.25);
    }

    //SETS FLOOR
    else if(val == 1)
    {
        setPixmap(QPixmap(":/Map/images/map/classFloor3.png"));
        this->setScale(0.25);
    }
    else if(val == 0)
    {
        setPixmap(QPixmap(":/Map/images/map/classFloor3_cracked.png"));
        this->setScale(0.25);
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

//              MINIMAP         //

void Tile::miniDesign()
{
    setPixmap(QPixmap(":/Other/images/other/unseen.png"));
}

void Tile::miniMove(int x, int y)
{
    this->setPos(x*39.2,y*16.8);
}

void Tile::miniCurrent()
{
    this->setPixmap(QPixmap(":/Other/images/other/current.png"));
}

void Tile::miniLast()
{
    this->setPixmap(QPixmap(":/Other/images/other/seen.png"));
}

