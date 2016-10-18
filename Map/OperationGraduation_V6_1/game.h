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



class Game : public QGraphicsView{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;

    Player *player;
};

#endif // GAME_H
