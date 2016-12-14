#ifndef LOGINCHILD_H
#define LOGINCHILD_H

#include <QMdiSubWindow>
#include "logindia.h"

namespace Ui {
class LoginChild;
}

class LoginChild : public QMdiSubWindow
{
public:
    LoginChild(QWidget *parent = 0);
    ~LoginChild();
    LoginDialog *login;
};

#endif // LOGINCHILD_H
