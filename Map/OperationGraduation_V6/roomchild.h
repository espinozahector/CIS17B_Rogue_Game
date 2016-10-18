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
    explicit RoomChild(QWidget *parent = 0);
    ~RoomChild();

private:
    Game *game;
};

#endif // ROOMCHILD_H
