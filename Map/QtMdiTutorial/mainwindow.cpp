#include <QtGui>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "childwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAbout(){
    QMessageBox::about(this, tr("About this demo"),
                       tr("This is a nice demo with some "
                          "crazy HTML content."));
}

void MainWindow::createChild()
{
    ChildWindow *childWindow = new ChildWindow(ui->mdiArea);
    childWindow->setAttribute(Qt::WA_DeleteOnClose);
    childWindow->show();
}
