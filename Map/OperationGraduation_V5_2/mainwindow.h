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
public:
    MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
