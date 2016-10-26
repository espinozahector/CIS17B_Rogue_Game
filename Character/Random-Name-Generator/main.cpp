#include "mainwindow.h"
#include <QApplication>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    String line1;
    ofstream myfile1;
    ofstream myfile2;
    myfile1.open ("prefix.txt");
    myfile2.open("suffix.txt");

    String prefix[25];
    String suffix[25];

    if (myfile1.is_open())
    {
    for (int i = 0; i < 25; i++)
        {
    while ( getline (myfile1,line1) )
             {
             prefix[i] = line1;
             }

        }
    }

    if (myfile2.is_open())
    {
    for (int i = 0; i < 25; i++)
        {
    while ( getline (myfile2,line1) )
             {
             prefix[i] = line1;
             }

        }
    }

    String prefix[25];
    String suffix{25};

    srand(time(0));

    randomPrefix = prefix[rand() % 25];
    randomSuffix = suffix[rand() % 25];

    myfile1.close();
    myfile2.close();
    return a.exec();


}
