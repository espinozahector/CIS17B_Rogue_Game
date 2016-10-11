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
    //set graphics on the tiles
    if(x==0 || y==0){
     setPixmap(QPixmap(":/tiles/wall.png"));
    }else if(x==15 || y==8){
     setPixmap(QPixmap(":/tiles/wall.png"));
    }else if(val==1){
     setPixmap(QPixmap(":/tiles/ClassFloor2.jpg"));
    }else if(val==0){
     setPixmap(QPixmap(":/tiles/obstacle.png"));
    }else{
     setPixmap(QPixmap(":/tiles/errorTile.png"));
    }
}

void Tile::setVal(int v)
{
    val = v;
}
