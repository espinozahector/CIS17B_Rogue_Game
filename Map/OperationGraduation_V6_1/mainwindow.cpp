#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    roomchild = 0;
    isInit = true;
    ui->setupUi(this);
    lgnScrn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lgnScrn()
{
    ui->mdiArea->setBackground(QColor("black"));
    loginchild = new LoginChild(ui->mdiArea);
    loginchild->setAttribute(Qt::WA_DeleteOnClose);
    loginchild->setWindowFlags(Qt::FramelessWindowHint);
    loginchild->show();
    loginchild->move(5,135);
}

void MainWindow::crRmCh()
{
    ui->mdiArea->setBackground(QColor("black"));
    roomchild = new RoomChild(ui->mdiArea);
    roomchild->setAttribute(Qt::WA_DeleteOnClose);
    roomchild->setWindowFlags(Qt::FramelessWindowHint);
    roomchild->show();
    roomchild->move(5,135);
}


void MainWindow::newGame()
{
    if(isInit)
    {
        isInit = false;
        delete loginchild;
        crRmCh();
    }
    else
    {
        delete roomchild;
        crRmCh();
    }
}
