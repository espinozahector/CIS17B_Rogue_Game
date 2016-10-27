/*
 * File:   Cols.cpp
 * Author: Victor and hector
 * Created on September 22, 2016, 10:42 PM
 * Purpose:
 */

#include "Cols.h"

Cols::Cols() //Default Constructor
{
    szCols = 16;
    szRows = 9;
    level = new Row*[szRows];

    for(int i = 0; i < szRows; i++)
    {
        level[i] = new Row(szCols);
    }
}

Cols::Cols(int newRows, int newCols) //Constructor with rows and columns parameter
{
    szRows = newRows;
    szCols = newCols;

    level = new Row*[szRows];

    for(int i = 0; i < szRows; i++)
    {
        level[i] = new Row(szCols);
    }
}

bool Cols::getData(int x, int y) // Get the data from the level array
{
    return level[x]->getEl(y);
}

Cols::~Cols()                   //Destructor
{
//    cout << "deleting cols" << endl;
    for(int i = 0; i < szRows; i++)
    {
        delete level[i];
    }
    delete [] level;
}
