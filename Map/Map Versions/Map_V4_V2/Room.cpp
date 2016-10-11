/* 
 * File:   Room.cpp
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:27 PM
 * Purpose: 
 */

#include "Room.h"


Room::Room()
{
    
}

Room::Room(int newRows, int newCols, int rows, int cols) : Map(newRows, newCols)
{
    rRows = rows;
    rCols = cols;
}

Room::~Room()
{
    
}

void Room::insRoom(int x, int y)
{
//    if(level[x]->getEl(y))
//    {
//        level[x]->getEl(y) = new Cols(rRows,rCols);
//        level[x]->getEl(y)->setEl(rRows,rCols);
//    }
//    else cout << "no room to build" << endl;
//    
//    for(int i = 0; i < rRows; i++)
//    {
//        for(int j = 0; j < rCols; j++)
//        {
//            
//        }
//    }
}
void Room::prntRoom()
{
//    for(int i = 0; i < rRows; i++)
//    {
//        for(int j = 0; j < rCols; j++)
//        {
//            
//        }
//        cout << endl;
//    }
}

void Room::prntRoom(int x, int y)
{
//    for(int i = 0; i < rRows; i++)
//    {
//        for(int j = 0; j < rCols; j++)
//        {
//            cout << level[x]->getEl(y);
//        }
//        cout << endl;
//    }
}