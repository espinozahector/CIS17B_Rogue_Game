#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>       //Container for game graphics items
#include <QGraphicsView>        //Renders the scene
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

#include "player.h"
#include "enemy.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *hp;

};

#endif // GAME_H
