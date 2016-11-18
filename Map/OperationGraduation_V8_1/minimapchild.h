#ifndef MINIMAPCHILD_H
#define MINIMAPCHILD_H

#include <QLabel>
#include <QMdiSubWindow>

class MiniMapChild : public QMdiSubWindow
{
    Q_OBJECT
public:
    MiniMapChild(QWidget *parent);
    ~MiniMapChild();
private:
    QLabel *tacobell; //A.K.A Minimap array of labels
public slots:
    void update(int,int);
    void clearTacos();
};

#endif // MINIMAPCHILD_H
