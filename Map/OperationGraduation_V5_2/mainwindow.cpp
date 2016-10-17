#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Game *game = new Game;

    setCentralWidget(game);


    game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    //create a background (commented since it did not look good)
    game->setBackgroundBrush(QBrush(QImage(":/Other/images/other/BackGroundGUI.jpg")));

    //centering the window to the desktop screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
}
