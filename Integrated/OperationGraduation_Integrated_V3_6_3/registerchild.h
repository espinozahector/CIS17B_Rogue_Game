#ifndef REGISTERCHILD_H
#define REGISTERCHILD_H

#include <QMdiSubWindow>
#include "registeruser.h"

namespace Ui
{
    class RegisterChild;
}

class RegisterChild : public QMdiSubWindow
{
public:
    RegisterChild(QWidget *parent = 0);
    ~RegisterChild();
    RegisterUser *nUser;
};

#endif // REGISTERCHILD_H
