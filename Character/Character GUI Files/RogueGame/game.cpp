#include "game.h"

#include "enemy.h"
#include "enemyfood.h"
#include "enemybomb.h"
#include "enemydebt.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game(QWidget *parent)
{
    //Create a scene
    scene = new QGraphicsScene();
    //Set scene size to (800, 600)
    scene->setSceneRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT);
    //Draw background
    setBackgroundBrush(QBrush(QImage(":/imgs/deps/map.png")));
    setScene(scene);


    //Disable scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Create an item to put into the scene
    player1 = new PJock("Bob");
    //Set player coordinates(middle of the screen, bottom - player height)
    player1->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - 100);
    //Enable item focus
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    //Sets item focus
    player1->setFocus();
    //Set item on scene
    scene->addItem(player1);

    //Create score
    score = new Score();
    scene->addItem(score);

    hp = new Health();
    hp->setPos(hp->x(), hp->y()+25);
    scene->addItem(hp);

    //Spawns enemies
    spawn();

    //Play background music
    QMediaPlayer *music = new QMediaPlayer();
    //Set sound file
    music->setMedia(QUrl("qrc:/sound/deps/bgmusic.mp3"));
    //Play music
    music->play();

    show();
}

void Game::spawn(){
    //Create enemies scaled by player level
    Enemy *enemy = new Enemy(player1->getLvl());
    EnemyFood *enemy2 = new EnemyFood(player1->getLvl());
    EnemyBomb *enemy3 = new EnemyBomb(player1->getLvl());
    EnemyDebt *enemy4 = new EnemyDebt(player1->getLvl());

    scene->addItem(enemy);
    scene->addItem(enemy2);
    scene->addItem(enemy3);
    scene->addItem(enemy4);
}


