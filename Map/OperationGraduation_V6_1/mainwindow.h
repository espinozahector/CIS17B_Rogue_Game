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
    void checkLineEdits();
    void prntAll();

private:
    QGraphicsScene *scene;
    QString uName;
    QString pass;
    QLabel *username;
    QLabel *password;
    QLineEdit *userLine;
    QLineEdit *passLine;
    QPushButton *submit;
    QPushButton *cancel;
    QPushButton *git;

    Ui::MainWindow *ui;
    RoomChild  *roomchild;
    LoginChild *loginchild;
    bool isInit;

private slots:
    void enableSubmitButton();
    void setUser();
    void website();

public slots:
    void lgnScrn();  //creats the login screen
    void crRmCh(); //create the room child
    void newGame(); //create the game
};

#endif // MAINWINDOW_H
