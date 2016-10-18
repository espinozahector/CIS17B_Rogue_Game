#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "roomchild.h"

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
    Ui::MainWindow *ui;
    RoomChild  *roomchild;
    bool isInit;

public slots:
    void crRmCh(); //create the room child
    void newGame(); //create the game
};

#endif // MAINWINDOW_H
