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

/*
 *  Need to be Fixed:
 *  map builder can be more efficient "when picking rooms, choose rooms that are suitable" - BrandEn
 *      - in level.cpp
 *  Need to change to window so that the focus is on the window and not each individual scene
 *      - example: the scene is getting built as the room only. We want the scene to include all "widgets in the window
 */
//System Libraries
#include <QApplication>
#include <iostream>

using namespace std;

//User Libraries
#include "mainwindow.h"

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int> (time(0)));
    //Begin qt execution
    QApplication a(argc, argv);
    MainWindow *mainWindow = new MainWindow;

    mainWindow->show();

    //Exit Stage Right
    return a.exec();
}
