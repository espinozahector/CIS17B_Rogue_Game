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
//    cout << "generating rooms into array\n";
    roomMap = new Room *[getNRooms()];

    int i = 0;
    for(int x = 0; x < getSzRows(); x++)
    {
        for(int y = 0; y < getSzCols(); y++)
        {
            if(level[x]->getEl(y))
            {
                roomMap[i++] = new Room(x,y,9,15);
            }
        }
    }
//    cout << "done generating\n";
    DoorsChk();
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

void Map::DoorsChk()
{
    bool *temp = new bool[4];
    for(int i = 0; i < 4; i++)
        temp[i] = 0;

    int numTemp = getNRooms();
    for(int i = 0; i < numTemp; i++)
    {
        for(int j = 0; j < numTemp; j++)
        {
            if(getRoomX(i) == getRoomX(j) && (getRoomY(i) - 1) == getRoomY(j)) // room above
                temp[0] = 1;

            if((getRoomX(i) + 1) == getRoomX(j) && getRoomY(i) == getRoomY(j)) // room to the right
                temp[1] = 1;

            if(getRoomX(i) == getRoomX(j) && (getRoomY(i) + 1) == getRoomY(j)) // room below
                temp[2] = 1;

            if((getRoomX(i) - 1) == getRoomX(j) && getRoomY(i) == getRoomY(j)) // room to the left
                temp[3] = 1;

            roomMap[i]->setDoors(temp);
            cout << roomMap[i]->getXLoc() << "," << roomMap[i]->getYLoc() << " doors = ";
            for(int i = 0; i < 4; i++)
                cout << temp[i] << ' ';
            cout << endl;
        }
    }
}
/*
 * 00000
 * 01110
 * 00000
 *
 * check the room to the right
 * check the room to the bottomr
 * check the room to the left
 * check the room to the top
 */

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
    return NULL;
}
