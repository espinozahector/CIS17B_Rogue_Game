#ifndef GAME_H
#define GAME_H

//System and Qt Libraries
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QList>
#include <QGraphicsItem>
#include <cstdlib>
#include <vector>

//User Libraries
#include "tile.h"
#include "map.h"
#include "player.h"
#include "binarybullet.h"


#include "enemy.h"
#include "enemyfood.h"
#include "enemybomb.h"
#include "enemydebt.h"


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
    Tile *tileSet;
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;

    //Enemy types
    vector<Enemy*> enmy_Exam;
    vector<EnemyFood*> enmy_Food;
    vector<EnemyBomb*> enmy_Bomb;
    vector<EnemyDebt*> enmy_Debt;


    QList<QGraphicsItem*> obstacles;
    void setObstacles();

    void delScene();
    void newScene(int, int);
    QMediaPlayer *getMusic() {return music;}
signals:
    void clearMini();
public slots:
    void changeRoom();
    void changeLvl();
    void playerAttack(int);

    //Spawn enemy
    void createEnemies(int);
    void spawn();
};

#endif // GAME_H
