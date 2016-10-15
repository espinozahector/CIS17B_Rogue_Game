#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QWidget>
#include <QtGui>
#include <QMdiSubWindow>

#include "mywidget.h"

namespace Ui {
    class ChildWindow;
}

class ChildWindow : public QMdiSubWindow
{
public:
    explicit ChildWindow(QWidget *parent=0);
    ~ChildWindow();
private:
    MyWidget *myWidget;
};

#endif // CHILDWINDOW_H
