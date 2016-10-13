#include "game.h"




Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //set random seed
//    srand(static_cast<unsigned int> (time(0)));

    //create the map
    Map base(9,9);

    setWindowTitle(tr("Operation Graduation"));

    //sample array for the room

    const int ROWS=9;
    const int COLS=15;
//    int samp[ROWS][COLS]={
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//        {0,1,1,1,1,1,3,1,1,1,1,1,1,1,1,0},
//        {0,1,1,2,1,1,1,1,1,2,1,2,1,1,1,0},
//        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//        {0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,0},
//        {0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,0},
//        {0,1,1,1,1,1,1,1,1,1,1,2,1,1,1,0},
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//    };

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720); //make the scene 800x600

    //create a background (commented since it did not look good)
    setBackgroundBrush(QBrush(QImage(":/images/BackGroundGUI.jpg")));

    //make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    //create the tiles
    Tile *tileSet;
    tileSet = new Tile[144];

    //row and column sizes


//    cout << "Room 4,4" << endl;
//    for(int i = 0; i < ROWS; i++)
//    {
//        for(int j = 0; j < COLS; j++)
//        {
//            cout << base.getRoom(4,4)->getRoomVal(i,j) << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;

    //iterate through array of tiles
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            //set map array values
            tileSet[(i*COLS)+j].setVal(base.getRoom(4,4)->getRoomVal(i,j));
//            tileSet[(i*COLS)+j].setVal(samp[i][j]);
            //set pixmaps
            tileSet[(i*COLS)+j].design(j,i);
            //position tiles
            tileSet[(i*COLS)+j].move(j,i);
            //add to scene
            scene->addItem(tileSet+((i*COLS)+j));
        }
    }

    //add player
    player = new Player();
    player->setPos(480,270);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

}
