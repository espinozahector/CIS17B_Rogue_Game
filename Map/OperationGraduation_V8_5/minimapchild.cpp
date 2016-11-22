#include "minimapchild.h"

MiniMapChild::MiniMapChild(QWidget *parent) :
    QMdiSubWindow(parent)
{
//    this->setFixedSize(350,150);
    this->setStyleSheet("background-color: #000;");

    tacobell = new mini(this);
    this->setWidget(tacobell);

    this->setFixedSize(350,150);
    tacobell->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tacobell->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

MiniMapChild::~MiniMapChild()
{

}

