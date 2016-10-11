#include "game.h"




Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //set random seed
//    srand(static_cast<unsigned int> (time(0)));

    //create the map
    Map base(9,9);

    setWindowTitle(tr("Room 1"));

    //sample array for the room
    int samp[9][16]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,3,1,1,1,1,1,1,1,1,0},
        {0,1,1,2,1,1,1,1,1,2,1,2,1,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,2,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,960,540); //make the scene 800x600

    //create a background (commented since it did not look good)
    //setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(960,540);

    //create the tiles
    Tile *tileSet;
    tileSet = new Tile[144];

    //row and column sizes
    int rows=16;
    int cols=9;


    //iterate through array of tiles
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //set map array values
            tileSet[(i*cols)+j].setVal(samp[j][i]);
            //set pixmaps
            tileSet[(i*cols)+j].design(i,j);
            //position tiles
            tileSet[(i*cols)+j].move(i,j);
            //add to scene
            scene->addItem(tileSet+((i*cols)+j));
        }
    }

    //add player
    player = new Player();
    player->setPos(480,270);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

}
