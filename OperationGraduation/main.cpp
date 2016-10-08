/*
 * Project: Operation Graduation (working title)
 * File: main.cpp
 * Authors: Branden Hitt.... (add your name here)
 * Created: October 7, 2016, 5:10pm
 * Purpose: Qt implementation of the map and character progress
 *
 */

/*
 * Notes:   Room Display Currently 960x540
 *                                 16 tiles by 9 tiles (60x60 pixels each)
 *                                 including surrounding grid for the wall
 *
 */
//System Libraries
#include <QApplication>
#include <iostream>

using namespace std;

//User Libraries
#include "game.h"

//Global Constants
Game *game;
//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[])
{
    //Begin qt execution
    QApplication a(argc, argv);

    game = new Game();

    game->show();


    //Exit Stage Right
    return a.exec();
}
