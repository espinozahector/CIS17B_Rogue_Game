/*
 * Project: Operation Graduation
 * File: main.cpp
 * Authors: Branden Hitt, Hector Espinoza , Victor Alcraz
 * Created: October 17, 2016,
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
#include <QTimer>
#include <qthread.h>
#include <iostream>

using namespace std;

//User Libraries
#include "replace.h"
#include "splash.h"

//Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int> (time(0)));
    //Begin qt execution
    QApplication a(argc, argv);

    Splash *splash = new Splash;

    splash->version();
    splash->update1();

    QThread::sleep(3);

    MainWindow *mainWindow = new MainWindow;

    splash->update2();

    QThread::sleep(3);

    mainWindow->show();
    splash->finish(mainWindow);
    delete splash;

    //Exit Stage Right
    return a.exec();
}
