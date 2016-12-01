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
    findEnd();
    setBossRoom();
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
    bool temp[4];

    int numTemp = getNRooms();
    for(int i = 0; i < numTemp; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            temp[k] = 0;
        }
        for(int j = 0; j < numTemp; j++)
        {
            if(i != j)
            {
                if(roomMap[i]->getXLoc() == roomMap[j]->getXLoc() && (roomMap[i]->getYLoc() - 1) == roomMap[j]->getYLoc()) // room above (left)
                    temp[3] = 1;

                if((roomMap[i]->getXLoc() + 1) == roomMap[j]->getXLoc() && roomMap[i]->getYLoc() == roomMap[j]->getYLoc()) // room to the right (bottom)
                    temp[2] = 1;

                if(roomMap[i]->getXLoc() == roomMap[j]->getXLoc() && (roomMap[i]->getYLoc() + 1) == roomMap[j]->getYLoc()) // room below (right)
                    temp[1] = 1;

                if((roomMap[i]->getXLoc() - 1) == roomMap[j]->getXLoc() && roomMap[i]->getYLoc() == roomMap[j]->getYLoc()) // room to the left (above)
                    temp[0] = 1;

                roomMap[i]->setDoors(temp);
            }
        }
    }

//    for(int i = 0; i < numTemp; i++)
//    {
//        cout << "temp dynamic array on setting doors: ";
//        cout << roomMap[i]->getXLoc() << "," << roomMap[i]->getYLoc() << " doors = ";
//        for(int i = 0; i < 4; i++)
//            cout << temp[i] << ' ';
//        cout << endl;
//    }

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
void Map::findEnd() //used to find the farthest location from the center
{
    int temp = 0;
    int length = 0;

    int tempX = 0;
    int tempY = 0;
    int a=0,b=0;
    for(int i = 0; i < this->getNRooms(); i++) //Distance Formula
    {
        a = getXStrt() - this->getRoomX(i);
        a *= a;
        b = getXStrt() - this->getRoomY(i);
        b *= b;
        temp = sqrt(a + b);
        if(temp >= length)
        {
            length = temp;
            temp = 0;
            tempX = this->getRoomX(i);
            tempY = this->getRoomY(i);
        }
    }
    cout << "length:" << length << endl;
    cout << "coordinate: " << tempX << " " << tempY << endl;
    farX = tempX;
    farY = tempY;
}

void Map::setBossRoom()
{

    vector<pair<int,int> > start;
    bool create = false;

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


//    getRoom(farX,farY)->prntRoom();
    cout << "F = " << farX << " , " << farY << endl;
    for(int x = 1; x < 9 - 1; x++)
    {
        for(int y = 1; y < 15 - 1; y++)
        {
            for(unsigned int i = 0 ; i < start.size();i++)
            {
                create = false;
                if(x == start[i].first && y == start[i].second)
                {
                    getRoom(farX,farY)->roomset(x,y,0);
                    create = true;
                    break;
                }
            }
            if(!create)
            {
                getRoom(farX,farY)->roomset(x,y,1);
            }
//            getRoom(farX,farY)->roomset(x,y,1);
        }
    }
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
    return NULL;
}
