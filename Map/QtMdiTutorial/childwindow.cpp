#include <QMdiSubWindow>

#include "childwindow.h"
#include "mywidget.h"

ChildWindow::ChildWindow(QWidget *parent): QMdiSubWindow(parent)
{
    myWidget = new MyWidget(this);
    this->setWidget(myWidget);
}

ChildWindow::~ChildWindow(){
    myWidget->~MyWidget();
}
