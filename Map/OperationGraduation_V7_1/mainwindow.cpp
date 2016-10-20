#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    roomchild = 0;
    isRoom = false;
    isLogin = true;
    ui->setupUi(this);
    lgnScrn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lgnScrn()
{
    isLogin = true;
    ui->mdiArea->setBackground(QColor("black"));
    loginchild = new LoginChild(ui->mdiArea);
    loginchild->setAttribute(Qt::WA_DeleteOnClose);
    loginchild->setWindowFlags(Qt::FramelessWindowHint);
    loginchild->show();
    loginchild->move(160,90);
}

void MainWindow::crRmCh()
{
    isRoom = true;
    ui->mdiArea->setBackground(QColor("black"));
    roomchild = new RoomChild(ui->mdiArea);
    roomchild->setAttribute(Qt::WA_DeleteOnClose);
    roomchild->setWindowFlags(Qt::FramelessWindowHint);
    roomchild->show();
    roomchild->move(5,135);

}


void MainWindow::newGame()
{
    if(isRoom)
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        roomchild->close();
        isRoom = false;
        crRmCh();
    }
    else
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        crRmCh();
    }
}
