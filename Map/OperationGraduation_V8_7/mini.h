#ifndef MINI_H
#define MINI_H

#include <QGraphicsView>
#include <tile.h>

class mini : public QGraphicsView
{
    Q_OBJECT
public:
    mini(QWidget *parent = 0);
    ~mini();
    void buildMini();
private:
    QGraphicsScene *miniScene;
    Tile *tile2;
    int miniR;  //Rows
    int miniC;  //Colums
    int lastX;
    int lastY;
public slots:
    void miniUpdate(int,int);
};

#endif // MINI_H
