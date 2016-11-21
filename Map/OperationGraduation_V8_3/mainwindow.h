#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCryptographicHash>
#include "roomchild.h"
#include "loginchild.h"
#include "statchild.h"
#include "minimapchild.h"
#include "connection.h"
#include "registerchild.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Connection createConnection();

private:
    QGraphicsScene *scene;

    Ui::MainWindow *ui;
    RoomChild  *roomchild;
    LoginChild *loginchild;
    StatChild *statchild;
    MiniMapChild *minichild;
    Connection connection;
    RegisterChild *regchild;
    bool isRoom;
    bool isLogin;
    bool isStat;
    bool isNUser;

private slots:

public slots:
    void crMnCh();   //creates the minimap child
    void lgnScrn();  //creates the login screen
    void crRmCh();   //creates the room child
    void crStCh();   //creates the status child
    void newGame();  //creates the game
    void newUser();  // creates new user screen
    void goBack();   // going back to login screen from new user screen
    void validate(); // validate username check
    void checkUser();// checks username and password credentials
};

#endif // MAINWINDOW_H
