#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "roomchild.h"
#include "loginchild.h"
#include "statchild.h"
#include "minimapchild.h"

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
    MiniMapChild *minichild;
    bool isRoom;
    bool isLogin;
    bool isStat;

private slots:

public slots:
    void crMnCh();   //creates the minimap child
    void lgnScrn();  //creates the login screen
    void crRmCh();   //creates the room child
    void crStCh();   //creates the status child
    void newGame();  //creates the game
};

#endif // MAINWINDOW_H
