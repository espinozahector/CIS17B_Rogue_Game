#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "roomchild.h"
#include "loginchild.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsScene *scene;

    Ui::MainWindow *ui;
    RoomChild  *roomchild;
    LoginChild *loginchild;
    bool isRoom;
    bool isLogin;

private slots:

public slots:
    void lgnScrn();  //creats the login screen
    void crRmCh();   //create the room child
    void newGame();  //create the game
};

#endif // MAINWINDOW_H
