#include "registerchild.h"

RegisterChild::RegisterChild(QWidget *parent) : QMdiSubWindow(parent)
{
    nUser = new RegisterUser(this);
    this->setWidget(nUser);

    nUser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    nUser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    nUser->setStyleSheet("border-image: url(:/Other/images/other/Title720.jpg) 0 0 0 0 stretch stretch");
    setFixedSize(1280,720);
}

RegisterChild::~RegisterChild()
{

}
