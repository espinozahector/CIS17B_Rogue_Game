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
    LoginChild(QWidget *parent);
    ~LoginChild();

private:
    LoginDialog *login;
};

#endif // LOGINCHILD_H
