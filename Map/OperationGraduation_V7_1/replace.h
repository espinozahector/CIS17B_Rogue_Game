#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    void crActns();         //create the actions
    void crMenu();          //create the menus
    void crTool();          //create the toolbar
    void crStatus();        //create the status bar
    enum { MaxRec = 5 };    //max recent files to be displayed

    QMenu *fileMenu;

    QAction *newAct;
    QAction *exitAct;
public slots:
    void crRmChd(); //create the room child
    void newGame(); //creates a new game
    void loadFiles(); //setup for game
};

#endif // MAINWINDOW_H
