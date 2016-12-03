#ifndef MINIMAPCHILD_H
#define MINIMAPCHILD_H

#include <QMdiSubWindow>
#include <QDebug>
#include <QWidget>
#include <QMouseEvent>

#include <mini.h>

class MiniMapChild : public QMdiSubWindow
{
    Q_OBJECT
public:
    MiniMapChild(QWidget *parent = 0);
    ~MiniMapChild();
    mini *tacobell;
    void setStuff();
protected:
    void mousePressEvent(QMouseEvent *mouseEvent);
    void keyPressEvent(QKeyEvent *keyEvent);
public slots:
    void newTacos();
signals:
    void reconnect();
    void miniClick();

};

#endif // MINIMAPCHILD_H
