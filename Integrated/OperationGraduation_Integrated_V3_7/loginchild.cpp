#include "loginchild.h"

LoginChild::LoginChild(QWidget *parent) : QMdiSubWindow(parent)
{
    login = new LoginDialog(this);
    this->setWidget(login);

    login->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    login->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    login->setStyleSheet("background-image: url(:/Other/images/other/Title720.jpg)");
    login->setStyleSheet("border-image: url(:/Other/images/other/Title720.jpg) 0 0 0 0 stretch stretch");
    setFixedSize(1280,720);
}

LoginChild::~LoginChild()
{
    login->setStyleSheet("");
}
