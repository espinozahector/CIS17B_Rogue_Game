/*
 * File:   Map.cpp
 * Author: Victor Alcaraz
 * Created on September 27, 2016, 12:42 PM
 * Purpose:
 */

#include "Map.h"


Map::Map()
{

}

Map::Map(int rows, int cols) : Room(rows,cols)
{
    cout << "generating rooms into array\n";
    roomMap = new Room *[getNRooms()];

    int i = 0;
    for(int x = 0; x < getSzRows(); x++)
    {
        for(int y = 0; y < getSzCols(); y++)
        {
            if(level[x]->getEl(y))
            {
                roomMap[i++] = new Room(x,y,9,16);
            }
        }
    }
    cout << "done generating\n";

    prntAll();
}

Map::~Map()
{
//    cout << "deleting Map" << endl;
    for(int i = 0;i < getNRooms(); i++)
    {
        delete roomMap[i];
    }
    delete [] roomMap;
}

void Map::prntAll()
{
    for(int x = 0; x < getNRooms(); x++)
    {
        roomMap[x]->prntRoom();
    }
}

void Map::prntSel()
{
    int x;
    int y;
    do{
        cout << "What room do you want to see?: [x,y]" << endl;
        cout << "x -> ";
        cin>>x;
        cout << "y -> ";
        cin>>y;
        if(x >= getSzRows() || y >= getSzCols() || x < 0 || y < 0)
        {
            cout << "You have selected a room that is out of bounds" << endl;
        }
    }while(x >= getSzRows() || y >= getSzCols() || x < 0 || y < 0);

    for(int i = 0; i < getNRooms(); i++)
    {
        if(roomMap[i]->getXLoc() == x && roomMap[i]->getYLoc() == y)
        {
            roomMap[i]->prntRoom();
            break;
        }
    }
}

Room *Map::getRoom(int x, int y)
{
    for(int i = 0; i < getNRooms(); i++)
    {
        if(roomMap[i]->getXLoc() == x && roomMap[i]->getYLoc() == y)
        {
            return roomMap[i];
        }
    }
}
