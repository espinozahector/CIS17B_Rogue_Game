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
    bool doors[4] = {0,0,0,0};
    rRows = nRows;
    rCols = nCols;
    size = 0;
    setLoc(x,y);
    bldRoom();
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
    vector<pair<int,int> > start;
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

void Room::setDoors(bool temp[])
{
    for(int i = 0; i < 4; i++)
        doors[i] = temp[i];
    cout << "doors dynamic array: ";
    cout << getXLoc() << "," << getYLoc() << " doors = ";
    for(int i = 0; i < 4;i++)
    {
        cout << doors[i] << " ";
    }
    cout << endl;
}

/*
 * iterate -> x -> y -> coords
 * bool check
 *      if blocks < numBlocks check = false;
 *      if blocks == numBlocks check = true;
 *
 *      if check == true
 *              iterate throught the rest and set to 1
 *
 *
 */
void Room::bldRoom()
{
    //Used to not block doors...
    vector<pair<int,int> > coordinates;

    //doors

    //walls

    //something else
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
    int blocks=0;
    int numblocks = 10;
    bool create = false;
    room = new Row *[rRows];

    for(int i = 0; i < rRows; i++)
    {
        room[i] = new Row(rCols);
    }

    for(int x = 1; x < rRows ; x++)
    {
        for(int y = 1; y < rCols; y++)
        {

            if(x != 8 && y != 14)
            {
                for(unsigned int i = 0 ; i < coordinates.size();i++)
                {
                    if(x == coordinates[i].first && y == coordinates[i].second)
                    {
                        room[x]->setEl(y,1);
                        create = true;
                        break;
                    }
                }
                if(!create)
                {
                    if(blocks < numblocks)
                    {
                        pTemp = rand();
                        crtPrc = rand()/3;
                        if (pTemp <= crtPrc)
                        {
                            room[x]->setEl(y,0);
                            blocks++;
                        }
                        else
                        {
                            room[x]->setEl(y,1);
                        }
                    }
                    else
                    {
                        room[x]->setEl(y,1);
                    }
                }
                else
                {
                    room[x]->setEl(y,1);
                }
                create = false;
            }
        }
    }
//    cout << "Room [" << this->getXLoc() << "," << this->getYLoc() << "] blocks: " << blocks << endl;

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
