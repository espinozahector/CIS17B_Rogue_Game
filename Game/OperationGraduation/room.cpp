/*
 * File:   Room.cpp
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:27 PM
 * Purpose:
 */

#include "Room.h"

Room::Room()
{
    size = 0;
}

Room::Room(int x, int y, int nRows, int nCols)
{
    rRows = nRows;
    rCols = nCols;
    size = 0;
    bldRoom();
    setLoc(x,y);
    size++;
}

Room::Room(int row, int col) : Level(row,col)
{
    size = 0;
}

Room::~Room()
{
    if(size >= 1)
    {
        for(int i = 0; i < rRows; i++)
        {
            delete room[i];
        }
        delete [] room;
    }
}


void Room::bldRoom()
{
    room = new Row *[rRows];

    for(int i = 0; i < rRows; i++)
    {
        room[i] = new Row(rCols);
    }

    for(int x = 0; x < rRows; x++)
    {
        for(int y = 0; y < rCols; y++)
        {
            int temp = rand()%2;
            room[x]->setEl(y,temp);
        }
    }
}

void Room::prntRoom()
{
    cout << "location: [" << this->getXLoc() << "," << this->getYLoc() << "]\n";
    for(int x = 0; x < rRows; x++)
    {
        for(int y = 0; y < rCols; y++)
        {
            if(room[x]->getEl(y)) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}
void Room::setLoc(int x,int y)
{
//    mymap.insert(make_pair(x,y),counter++);
    xLoc = x;
    yLoc = y;
}
