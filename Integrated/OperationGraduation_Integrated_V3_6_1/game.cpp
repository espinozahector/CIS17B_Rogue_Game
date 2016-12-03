#include "game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //create the map
    Map *base = new Map(9,9);
    base2 = base;
    base2->printmap();

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,540); //make the scene 800x600
    setFixedSize(900,540);
    //make the newly created scene the scene to visualize
    setScene(scene);

    //this is only here to make it run
    gRows = 9;
    gCols = 15;

    //add player
    player = new Player(base);
    player->setPos(420,240); //player starting position
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    player->setFocus();

    newScene(player->getMapX(),player->getMapY());
    scene->addItem(player);
    connect(player,SIGNAL(enterDoor()),this, SLOT(changeRoom()));
    connect(player,SIGNAL(newLevel()),this,SLOT(changeLvl()));
    connect(player, SIGNAL(newBullet(int)),this,SLOT(playerAttack(int)));
    player->setZValue(10);
//    cout << " player z value = " << player->zValue() << endl;

//    for(int i=0;i<gRows;i++){
//        for(int j=0;j<gCols;j++){
//            player->setFocusProxy(tileSet);
//            tileSet[(i*gCols)+j].setFocusProxy(player);
//        }
//    }

    // play music
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/audio/audio/02 - Messa Da Requiem_ II. Dies Irae_cut.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->setVolume(1);
    music->play();
}

void Game::setObstacles()
{
    for(int i=0;i<gRows;i++){
        for(int j=0;j<gCols;j++){
            if(tileSet[(i*gCols)+j].getVal() == 0)
            {
//                obstacles.append((*tileSet[(i*gCols)+j]));
            }
        }
    }
    qDebug() << "Obstacles size : " << obstacles.size();
}

void Game::changeRoom()
{
    cout << "changeRoom: " << endl;
    base2->getRoom(player->getMapX(),player->getMapY())->prntRoom();
    cout << "current room ";
    cout << base2->getRoom(player->getMapX(),player->getMapY())->getXLoc() << " ";
    cout << base2->getRoom(player->getMapX(),player->getMapY())->getYLoc() << endl;
//    cout << "deleting old scene" << endl;
    delScene();
//    cout << "setting player position" << endl;
    player->setPos(420,240);
//    cout << "setting new scene" << endl;
    newScene(player->getMapX(),player->getMapY());
//    cout << "removing player" << endl;
//    scene->removeItem(player);
//    cout << "setFocus" << endl;
//    player->setFocus();
//    cout << "adding player" << endl;
//    scene->addItem(player);

    //    cout << " player z value = " << player->zValue() << endl;

}

void Game::changeLvl()
{
    base2 = new Map(9,9);
    player->setMapX(4);
    player->setMapY(4);
    player->setLvlCnt(player->getLvlCnt()+1);
    player->setMap(base2);
    emit clearMini();
    changeRoom();
    this->setFocus();
    player->setFocus();
}

void Game::playerAttack(int dir)
{
    BinaryBullet *bullet = new BinaryBullet;
    bullet->setDir(dir);
    bullet->setPos(player->x(), player->y());
    scene->addItem(bullet);
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
//    cout << "creating new tileset" << endl;
    tileSet = new Tile[135];
//    cout << "temp bool initialization" << endl;
    bool temp[4] = {0,0,0,0};

//    cout << "copying doors to temp" << endl;
    for(int i = 0; i < 4; i++)
        temp[i] = base2->getRoom(x,y)->getDoors(i);

//    cout << "door temp: ";
//    for(int i = 0; i < 4; i++)
//        cout << temp[i] << ' ';
//    cout << endl;

//    cout << "iterate through array of tiles" << endl;
    //iterate through array of tiles
    for(int i=0;i<gRows;i++){
        for(int j=0;j<gCols;j++){
            //set map array values
            tileSet[(i*gCols)+j].setVal(base2->getRoom(x,y)->getRoomVal(i,j));
            //set pixmaps
            tileSet[(i*gCols)+j].design(j,i,temp);
            //position tiles
            tileSet[(i*gCols)+j].move(j,i);

//            tileSet[(i*gCols)+j].setAcceptTouchEvents(false);
            //add to scene
            scene->addItem(tileSet+((i*gCols)+j));
        }
    }

    setObstacles();

    if(player->isBoss2)
    {
        Tile *hatch = new Tile();
        hatch->setPixmap(QPixmap(":/Map/images/map/TrapDoor.png"));
        hatch->setScale(0.25);
        hatch->move(7,4);
        scene->addItem(hatch);
    }
    int count = 0;
    for(int i = 1;i < gRows - 1; i++){
        for(int j = 1;j < gCols - 1; j++){
            if(base2->getRoom(player->getMapX(),player->getMapY())->getRoomVal(i,j) == 0)
            {
                count++;
            }
        }
    }
//    qDebug() << count;
//    if(!holes.isEmpty())
//    {
//        holes.clear();
//    }
//    for(int i = 0; i <135; i++)
//    {
//        if(tileSet[i].getVal() == 0)
//        {
//            holes.append(tileSet[i]);
//        }
//    }
    //    qDebug() << holes.size() << endl;
}

