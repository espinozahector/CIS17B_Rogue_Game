#include "loginchild.h"

LoginChild::LoginChild(QWidget *parent) : QMdiSubWindow(parent)
{
    login = new LoginDialog(this);
    this->setWidget(login);

    login->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    login->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    login->setStyleSheet("background-image: url(:/Other/images/other/Title720.jpg)");
    setFixedSize(900,540);
}

LoginChild::~LoginChild()
{

}
