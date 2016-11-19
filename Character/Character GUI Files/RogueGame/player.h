#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

#include "enemy.h"

class Player : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QMediaPlayer *bulletsound;

public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER_H
