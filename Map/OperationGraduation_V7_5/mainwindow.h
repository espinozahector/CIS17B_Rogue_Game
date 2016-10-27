#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "roomchild.h"
#include "loginchild.h"
#include "statchild.h"

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
    StatChild *statchild;
    bool isRoom;
    bool isLogin;
    bool isStat;

private slots:

public slots:
    void lgnScrn();  //creats the login screen
    void crRmCh();   //create the room child
    void crStCh();   //create the status child
    void newGame();  //create the game
};

#endif // MAINWINDOW_H
