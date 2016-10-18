#include "loginchild.h"

LoginChild::LoginChild(QWidget *parent) : QMdiSubWindow(parent)
{
    login = new LoginDialog(this);
    this->setWidget(login);

    login->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    login->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,540);
}
