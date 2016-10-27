#include "roomchild.h"

RoomChild::RoomChild(QWidget *parent) :
    QMdiSubWindow(parent)
{
    game = new Game(this);
    this->setWidget(game);

    game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,540);
    //create a background (commented since it did not look good)
//    game->setBackgroundBrush(QBrush(QImage(":/Other/images/other/BackGroundGUI.jpg")));

}

RoomChild::~RoomChild()
{
    game->~Game();
}
