#ifndef MINIMAPCHILD_H
#define MINIMAPCHILD_H

#include <QLabel>
#include <QMdiSubWindow>
#include <QDebug>

class MiniMapChild : public QMdiSubWindow
{
    Q_OBJECT
public:
    MiniMapChild(QWidget *parent = 0);
    ~MiniMapChild();
private:
    QLabel *tacobell; //A.K.A Minimap array of labels
public slots:
//    void update(int,int);
//    void clearTacos();
};

#endif // MINIMAPCHILD_H
