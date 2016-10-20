#include "game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //create the map
    Map *base = new Map(9,9);
    base2 = base;
    base2->printmap();
    //delete base;

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

    newScene(player->getMapX(),player->getMapY());
    scene->addItem(player);
    connect(player,SIGNAL(enterDoor()),this, SLOT(changeRoom()));
    player->setZValue(5);
//    cout << " player z value = " << player->zValue() << endl;
}

void Game::changeRoom()
{
    cout << "changeRoom: " << endl;
    base2->getRoom(player->getMapX(),player->getMapY())->prntRoom();
    cout << "current room ";
    cout << base2->getRoom(player->getMapX(),player->getMapY())->getXLoc() << " ";
    cout << base2->getRoom(player->getMapX(),player->getMapY())->getYLoc() << endl;
    cout << "deleting old scene" << endl;
    delScene();
    cout << "setting player position" << endl;
    player->setPos(420,250);
    cout << "setting new scene" << endl;
    newScene(player->getMapX(),player->getMapY());
//    cout << "removing player" << endl;
//    scene->removeItem(player);
//    cout << "setFocus" << endl;
//    player->setFocus();
//    cout << "adding player" << endl;
//    scene->addItem(player);

//    cout << " player z value = " << player->zValue() << endl;
}

void Game::delScene()
{
    QList<QGraphicsItem*> items = scene->items();
//    std::cout << items.size() << std::endl;
    for (int i = 1; i < items.size(); i++) {
        scene->removeItem(items[i]);
        delete items[i];
    }
}

void Game::newScene(int x, int y)
{
    cout << "creating new tileset" << endl;
    Tile *tileSet;
    tileSet = new Tile[135];
    cout << "temp bool initialization" << endl;
    bool temp[4] = {0,0,0,0};

    cout << "copying doors to temp" << endl;
    for(int i = 0; i < 4; i++)
        temp[i] = base2->getRoom(x,y)->getDoors(i);

    cout << "door temp: ";
    for(int i = 0; i < 4; i++)
        cout << temp[i] << ' ';
    cout << endl;

    cout << "iterate through array of tiles" << endl;
    //iterate through array of tiles
    for(int i=0;i<gRows;i++){
        for(int j=0;j<gCols;j++){
            //set map array values
            tileSet[(i*gCols)+j].setVal(base2->getRoom(x,y)->getRoomVal(i,j));
            //set pixmaps
            tileSet[(i*gCols)+j].design(j,i,temp);
            //position tiles
            tileSet[(i*gCols)+j].move(j,i);
            //add to scene
            scene->addItem(tileSet+((i*gCols)+j));
        }
    }
}
