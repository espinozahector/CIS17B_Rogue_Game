#include "game.h"




Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //create the map
    Map base(9,9);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720); //make the scene 800x600

    //make the newly created scene the scene to visualize
    setScene(scene);


    //add player
    player = new Player();
    player->setPos(480,270);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

}
