#include "game.h"


Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //create the map
    Map base(9,9);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720); //make the scene 800x600

    //make the newly created scene the scene to visualize
    setScene(scene);

    //this is only here to make it run
    int rows = 9;
    int cols = 15;

    //newRoom = new QWidget;
    //newRoom->setFixedSize(960,540);
    //create the tiles
    Tile *tileSet;
    tileSet = new Tile[144];

    //iterate through array of tiles
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //set map array values
            tileSet[(i*cols)+j].setVal(base.getRoom(4,4)->getRoomVal(i,j));
//            tileSet[(i*COLS)+j].setVal(samp[i][j]);
            //set pixmaps
            tileSet[(i*cols)+j].design(j,i);
            //position tiles
            tileSet[(i*cols)+j].move(j,i);
            //add to scene
            scene->addItem(tileSet+((i*cols)+j));
        }
    }

    //add player
    player = new Player();
    player->setPos(440,420); //player starting position
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

}
