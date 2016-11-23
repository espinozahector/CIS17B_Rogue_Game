#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>       //Container for game graphics items
#include <QGraphicsView>        //Renders the scene
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

#include "pjock.h"
#include "score.h"
#include "health.h"



class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    PJock *player1;
    Score *score;
    Health *hp;
public slots:
    void spawn();
    void checkCollision();

};

#endif // GAME_H
