#ifndef GAME_H
#define GAME_H

//System and Qt Libraries
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>

//User Libraries
#include "tile.h"
#include "map.h"
#include "player.h"

#include <iostream>
using namespace  std;


class Game : public QGraphicsView{
    Q_OBJECT
private:
    QMediaPlaylist *playlist;
    QMediaPlayer *music;
    int gRows;
    int gCols;
    Map *base2;
public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    Player *player;

    void delScene();
    void newScene(int, int);
    QMediaPlayer *getMusic() {return music;}

signals:
    //void update2();
public slots:
    void changeRoom();
};

#endif // GAME_H
