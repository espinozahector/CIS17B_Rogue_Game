#include "minimapchild.h"

#include <QDebug>
MiniMapChild::MiniMapChild(QWidget *parent) :
    QMdiSubWindow(parent)
{
//    this->setFixedSize(350,150);
    this->setStyleSheet("background-color: #000;");

    tacobell = new mini(this);
    setStuff();
}

void MiniMapChild::newTacos()
{
//    delete tacobell;
    tacobell = new mini(this);
    setStuff();
    emit reconnect();
}

void MiniMapChild::setStuff()
{
    this->setWidget(tacobell);

    this->setFixedSize(350,150);
    tacobell->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tacobell->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MiniMapChild::mousePressEvent(QMouseEvent *mouseEvent)
{
    mouseEvent->ignore();
//    qDebug() << mouseEvent;
//    qDebug() << "caught the event";
    emit miniClick();
}

void MiniMapChild::keyPressEvent(QKeyEvent *keyEvent)
{
    qDebug() << "mini clicked";
    keyEvent->ignore();
    emit miniClick();
}

MiniMapChild::~MiniMapChild()
{

}

