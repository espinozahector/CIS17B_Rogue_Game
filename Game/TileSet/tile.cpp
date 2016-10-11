#include "tile.h"

Tile::Tile(QGraphicsItem *parent)
{
       //do nothing but create the tile
}

void Tile::move(int x, int y)
{
    this->setPos((x*60),(y*60));
}

void Tile::design(int x, int y)
{
    //set graphics on the tiles
    if(x==0 || y==0){
     setPixmap(QPixmap(":/tiles/wall.png"));
    }else if(x==15 || y==8){
     setPixmap(QPixmap(":/tiles/wall.png"));
    }else if(val==1){
     setPixmap(QPixmap(":/tiles/floor.png"));
    }else if(val==2){
     setPixmap(QPixmap(":/tiles/obstacle.png"));
    }else{
     setPixmap(QPixmap(":/tiles/errorTile.png"));
    }
}

void Tile::setVal(int v)
{
    val=v;
}
