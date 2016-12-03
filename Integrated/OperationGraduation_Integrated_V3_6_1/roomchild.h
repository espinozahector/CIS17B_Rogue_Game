#ifndef ROOMCHILD_H
#define ROOMCHILD_H

#include <QWidget>
#include <QMdiSubWindow>
#include <QMouseEvent>

#include "game.h"

namespace Ui {
class RoomChild;
}

class RoomChild : public QMdiSubWindow
{
    Q_OBJECT

public:
    RoomChild(QWidget *parent = 0);
    ~RoomChild();
    Game *game;

    void mousePressEvent(QMouseEvent *mouseEvent);
private:

signals:
    void gameClick();
    void roomToMain();

};

#endif // ROOMCHILD_H
