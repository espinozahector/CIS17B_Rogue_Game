#ifndef PLAYER_H
#define PLAYER_H

//System and Qt Libraries
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
