#include "game.h"


Game::Game(QWidget *parent) : QGraphicsView(parent)
  //ui(new Ui::Game)
{
    //ui->setupUi(this);
    //create the map
    Map base(9,9);
    base.printmap();
    //test vector reassignment
//    bool *temp = base.getRoom(4,4)->getDoors();

//    for(int i = 0; i < 4; i++)
//        cout << temp[i] << ' ';
//    cout << endl;

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,540); //make the scene 800x600
    setFixedSize(900,540);
    //make the newly created scene the scene to visualize
    setScene(scene);
    //this is only here to make it run
    gRows = 9;
    gCols = 15;


    //add player
    player = new Player();
    player->setPos(420,250); //player starting position
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    newScene(base,player->getMapX(),player->getMapY());
    scene->addItem(player);

    //newRoom = new QWidget;
    //newRoom->setFixedSize(960,540);
    //create the tiles
//    Tile *tileSet;
//    tileSet = new Tile[144];

//    //iterate through array of tiles
//    for(int i=0;i<rows;i++){
//        for(int j=0;j<cols;j++){
//            //set map array values
//            tileSet[(i*cols)+j].setVal(base.getRoom(4,4)->getRoomVal(i,j));
//            tileSet[(i*COLS)+j].setVal(samp[i][j]);
//            //set pixmaps
//            tileSet[(i*cols)+j].design(j,i);
//            //position tiles
//            tileSet[(i*cols)+j].move(j,i);
//            //add to scene
//            scene->addItem(tileSet+((i*cols)+j));
//        }
//    }
//    tileSet[(2*cols)+2].setVal(3);
//    tileSet[(2*cols)+2].design(25,25);



}

void Game::changeRoom(Map &base)
{
    delScene();
    newScene(base,player->getMapX(),player->getMapY());
    scene->removeItem(player);
    player->setFocus();
    scene->addItem(player);
}

void Game::delScene()
{
    QList<QGraphicsItem*> items = scene->items();
//    std::cout << items.size() << std::endl;
    for (int i = 0; i < items.size()-1; i++) {
        scene->removeItem(items[i]);
        delete items[i];
    }
}

void Game::newScene(Map &base,int x, int y)
{

    Tile *tileSet;
    tileSet = new Tile[135];
    bool temp[4] = {0,0,0,0};
    for(int i = 0; i < 4; i++)
        temp[i] = base.getRoom(x,y)->getDoors(i);

    cout << "door temp: ";
    for(int i = 0; i < 4; i++)
        cout << temp[i] << ' ';
    cout << endl;
    //iterate through array of tiles
    for(int i=0;i<gRows;i++){
        for(int j=0;j<gCols;j++){
            //set map array values
            tileSet[(i*gCols)+j].setVal(base.getRoom(x,y)->getRoomVal(i,j));
            //set pixmaps
            tileSet[(i*gCols)+j].design(j,i,temp);
            //position tiles
            tileSet[(i*gCols)+j].move(j,i);
            //add to scene
            scene->addItem(tileSet+((i*gCols)+j));
        }
    }
    delete [] temp;
}
