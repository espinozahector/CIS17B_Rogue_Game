#include "game.h"


#include <typeinfo>

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
    connect(this, SIGNAL(awardXP()), player, SLOT(recXP()));
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
    //Despawn enemies
    //despawn();

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

    int enemy_max = (rand()%4)+2;

    if(player->isBoss2)
    {
        Tile *hatch = new Tile();
        hatch->setPixmap(QPixmap(":/Map/images/map/TrapDoor.png"));
        hatch->setScale(0.25);
        hatch->move(7,4);
        scene->addItem(hatch);
    }
    //else if(player->getMapX() != 4 || player->getMapY() !=4 )
    else{
        //Create enemies
        createEnemies(enemy_max);
        spawn();
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

void Game::createEnemies(int max){

    if(max > 0){
        //Enemy vector size
        int enmy1=0;//Exam
        int enmy2=0;//Food
        int enmy3=0;//Bomb
        int enmy4=0;//Debt


        for(int i = 0; i < max; i++){
            int enemy_type = rand()%4;

            switch(enemy_type){
                case 0:
                    enmy1++;
                    break;

                case 1:
                    enmy2++;
                    break;

                case 2:
                    enmy3++;
                    break;

                default:
                    enmy4++;
                    break;
            }
        }

        enmy_Exam.resize(enmy1);
        enmy_Food.resize(enmy2);
        enmy_Bomb.resize(enmy3);
        enmy_Debt.resize(enmy4);
    }
}

void Game::spawn(){
    //Create enemies scaled by player level

    if(enmy_Exam.size() > 0){
        for(int i = 0 ; i < enmy_Exam.size(); i++){
            enmy_Exam[i] = new Enemy(player->getLvl());
            connect(enmy_Exam[i], SIGNAL(death()), this, SLOT(enemyDied()));
            scene->addItem(enmy_Exam[i]);
        }
    }

    if(enmy_Food.size() > 0){
        for(int i = 0 ; i < enmy_Food.size(); i++){
            enmy_Food[i] = new EnemyFood(player->getLvl());
            connect(enmy_Food[i], SIGNAL(death()), this, SLOT(enemyDied()));
            scene->addItem(enmy_Food[i]);
        }
    }


    if(enmy_Bomb.size() > 0){
        for(int i = 0 ; i < enmy_Bomb.size(); i++){
            enmy_Bomb[i] = new EnemyBomb(player->getLvl());
            connect(enmy_Bomb[i], SIGNAL(death()), this, SLOT(enemyDied()));
            scene->addItem(enmy_Bomb[i]);
        }
    }

    if(enmy_Debt.size() > 0){
        for(int i = 0 ; i < enmy_Debt.size(); i++){
            enmy_Debt[i] = new EnemyDebt(player->getLvl());
            connect(enmy_Debt[i], SIGNAL(death()), this, SLOT(enemyDied()));
            scene->addItem(enmy_Debt[i]);
        }
    }

}

void Game::enemyDied()
{
    emit awardXP();
}

/*
void Game::despawn(){

    if(enmy_Exam.size() > 0){
        for(int i = 0; i < enmy_Exam.size(); i++){
            scene->removeItem(enmy_Exam[i]);

            //enmy_Exam[i] = NULL;
            delete enmy_Exam[i];
        }
    }

    if(enmy_Food.size() > 0){
        for(int i = 0; i < enmy_Food.size(); i++){
            scene->removeItem(enmy_Food[i]);
            //enmy_Food[i] = NULL;
            delete enmy_Food[i];
        }
    }


    if(enmy_Bomb.size() > 0){
        for(int i = 0; i < enmy_Bomb.size(); i++){
            if(enmy_Bomb[i] != NULL){
                scene->removeItem(enmy_Bomb[i]);

                enmy_Bomb[i] = NULL;
                delete enmy_Bomb[i];
            }
        }
    }

    if(enmy_Debt.size() > 0){
        for(int i = 0; i < enmy_Debt.size(); i++){
            scene->removeItem(enmy_Debt[i]);

            //enmy_Debt[i] = NULL;
            delete enmy_Debt[i];
        }
    }
    qDebug() <<"Enemies deleted";
}
*/
