#ifndef ROOMCHILD_H
#define ROOMCHILD_H

#include <QWidget>
#include <QMdiSubWindow>

#include "game.h"

namespace Ui {
class RoomChild;
}

class RoomChild : public QMdiSubWindow
{


public:
    RoomChild(QWidget *parent = 0);
    ~RoomChild();
    Game *game;
private:
};

#endif // ROOMCHILD_H
