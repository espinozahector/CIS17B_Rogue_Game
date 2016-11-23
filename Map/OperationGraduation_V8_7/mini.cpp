#include "mini.h"

mini::mini(QWidget *parent) : QGraphicsView(parent)
{
    miniR = 9;
    miniC = 9;
    lastX = 4;
    lastY = 4;
    miniScene = new QGraphicsScene();
    miniScene->setSceneRect(0,0,350,150);
    this->setAttribute(Qt::WA_ShowWithoutActivating);
    setFixedSize(350,150);

    setScene(miniScene);
    buildMini();
}

mini::~mini()
{

}

void mini::buildMini()
{
    tile2 = new Tile[81];

    for(int i = 0 ;i < miniR;i++)
    {
        for(int j = 0; j < miniC;j++)
        {
            tile2[(i*miniC)+j].miniDesign();
            tile2[(i*miniC)+j].miniMove(j,i);
            tile2[(i*miniC)+j].setAcceptTouchEvents(false);
            miniScene->addItem(tile2+((i*miniC)+j));
        }
    }
    tile2[(4*miniC)+4].miniCurrent();
}

void mini::miniUpdate(int x, int y)
{
    tile2[(lastX*miniC)+lastY].miniLast();
    tile2[(x*miniC)+y].miniCurrent();

    lastX = x;
    lastY = y;
}
