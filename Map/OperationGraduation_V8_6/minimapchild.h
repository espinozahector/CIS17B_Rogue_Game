#ifndef MINIMAPCHILD_H
#define MINIMAPCHILD_H

#include <QMdiSubWindow>
#include <QDebug>
#include <QWidget>

#include <mini.h>

class MiniMapChild : public QMdiSubWindow
{
    Q_OBJECT
public:
    MiniMapChild(QWidget *parent = 0);
    ~MiniMapChild();
    mini *tacobell;
    void setStuff();
public slots:
    void newTacos();
signals:
    void reconnect();

};

#endif // MINIMAPCHILD_H