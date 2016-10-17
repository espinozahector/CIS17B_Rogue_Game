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

//Start room should be open
void Room::startRoom()
{
    vector<pair<int,int>> start;
    start.push_back(make_pair(1,1));
    start.push_back(make_pair(2,1));
    start.push_back(make_pair(1,2));

    start.push_back(make_pair(6,1));
    start.push_back(make_pair(7,1));
    start.push_back(make_pair(7,2));

    start.push_back(make_pair(1,12));
    start.push_back(make_pair(1,13));
    start.push_back(make_pair(2,13));

    start.push_back(make_pair(7,12));
    start.push_back(make_pair(7,13));
    start.push_back(make_pair(6,13));

}
void Room::bldRoom()
{
    //Used to not block doors...
    vector<pair<int,int>> coordinates;
    coordinates.push_back(make_pair(0,7));
    coordinates.push_back(make_pair(1,6));
    coordinates.push_back(make_pair(1,7));
    coordinates.push_back(make_pair(1,8));
    coordinates.push_back(make_pair(2,7));
    coordinates.push_back(make_pair(8,7));
    coordinates.push_back(make_pair(3,13));
    coordinates.push_back(make_pair(4,12));
    coordinates.push_back(make_pair(4,13));
    coordinates.push_back(make_pair(5,13));
    coordinates.push_back(make_pair(4,0));
    coordinates.push_back(make_pair(6,7));
    coordinates.push_back(make_pair(7,6));
    coordinates.push_back(make_pair(7,7));
    coordinates.push_back(make_pair(7,8));
    coordinates.push_back(make_pair(4,14));
    coordinates.push_back(make_pair(3,1));
    coordinates.push_back(make_pair(4,1));
    coordinates.push_back(make_pair(4,2));
    coordinates.push_back(make_pair(5,1));

    float crtPrc;
    float pTemp;
    char temp;
    room = new Row *[rRows];

    for(int i = 0; i < rRows; i++)
    {
        room[i] = new Row(rCols);
    }

    for(int x = 0; x < rRows ; x++)
    {
        for(int y = 0; y < rCols; y++)
        {
            for(unsigned int i = 0 ; i < coordinates.size();i++)
            {
                if(x == coordinates[i].first && y == coordinates[i].second)
                {
                    room[x]->setEl(y,1);
                    break;
                }
                else
                {
                    pTemp = rand();
                    crtPrc = rand()/3;
                    if (pTemp <= crtPrc)
                    {
                        temp = 0;
                    }
                    else temp = 1;
                    room[x]->setEl(y,temp);
                }
            }
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
    xLoc = x;
    yLoc = y;
}

bool Room::getRoomVal(int x,int y)
{
    return room[x]->getEl(y);
}
