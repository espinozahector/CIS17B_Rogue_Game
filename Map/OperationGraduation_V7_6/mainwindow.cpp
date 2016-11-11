#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    roomchild = 0;
    isRoom = false;
    isStat = false;
    isLogin = true;
    ui->setupUi(this);
    lgnScrn();
//    this->setCursor(Qt::BlankCursor); //only makes cursor visible, needs to remove it totally
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crMnCh()
{
    minichild = new MiniMapChild(ui->mdiArea);
    minichild->setAttribute(Qt::WA_DeleteOnClose);
    minichild->setWindowFlags(Qt::FramelessWindowHint);
    minichild->show();
    minichild->move(925,5);
}

void MainWindow::lgnScrn()
{
    isLogin = true;
    ui->mdiArea->setBackground(QColor("black"));
    loginchild = new LoginChild(ui->mdiArea);
    loginchild->setAttribute(Qt::WA_DeleteOnClose);
    loginchild->setWindowFlags(Qt::FramelessWindowHint);
    loginchild->show();
}

void MainWindow::crRmCh()
{
//    else
//    {
//        roomchild->game->getMusic()->play();
//    }

    isRoom = true;
//    ui->mdiArea->setBackground(QColor("black"));
    roomchild = new RoomChild(ui->mdiArea);
    roomchild->setAttribute(Qt::WA_DeleteOnClose);
    roomchild->setWindowFlags(Qt::FramelessWindowHint);
    roomchild->show();
    roomchild->move(5,155);
    crMnCh();
}

void MainWindow::crStCh()
{
    isStat = true;
//    ui->mdiArea->setBackground(QColor("black"));
    statchild = new StatChild(ui->mdiArea);
    statchild->setAttribute(Qt::WA_DeleteOnClose);
    statchild->setWindowFlags(Qt::FramelessWindowHint);
    statchild->setFixedSize(900,150);
    statchild->show();
    statchild->move(5,0);
    std::cout<<"Status Child Created"<<std::endl;
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
        if(roomchild->game->getMusic()->state() == QMediaPlayer::PlayingState)
        {
            delete roomchild->game->getMusic();
        }
        roomchild->close();
        isRoom = false;
        crStCh();
        crRmCh();
    }
    else
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        crStCh();
        crRmCh();
    }
}
