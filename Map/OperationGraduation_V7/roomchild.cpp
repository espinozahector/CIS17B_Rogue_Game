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

    //centering the window to the desktop screen
//    QRect screenGeometry = QApplication::desktop()->screenGeometry();
//    int x = (screenGeometry.width()-this->width()) / 2;
//    int y = (screenGeometry.height()-this->height()) / 2;
//    this->move(x, y);
}

RoomChild::~RoomChild()
{
    game->~Game();
}
