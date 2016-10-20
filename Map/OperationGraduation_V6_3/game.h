#ifndef GAME_H
#define GAME_H

//System and Qt Libraries
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

//User Libraries
#include "tile.h"
#include "map.h"
#include "player.h"

#include <iostream>
using namespace  std;


class Game : public QGraphicsView{
private:
    int gRows;
    int gCols;
public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    Player *player;
    void delScene();
    void newScene(Map&,int,int);
    void changeRoom(Map&);

private slots:

public slots:

};

#endif // GAME_H
