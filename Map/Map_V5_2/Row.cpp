/* 
 * File:   Row.cpp
 * Author: Hector and victor
 * Created on September 24, 2016
 * Purpose: Base Row of map
 */

#include "Row.h"

Row::Row() //Default constructor
{    
    cols = 9;
    table = new bool[cols];
    
    for(int i = 0; i < cols; i++)
    {
        table[i] = 0;
    }
}

Row::Row(int newRow) //Constructor with columns parameter
{
    cols = newRow;
    table = new bool[cols];
    
    for(int i = 0; i < cols; i++)
    {
        table[i] = 0;
    }
}

void Row::setEl(int y)  // sets the element in the row to true
{ 
    table[y] = 1;
}


Row::~Row() //Destructor
{
//    cout << "deleting row" << endl;
    delete [] table;
}

void Row::setEl(int y,int value)
{
    table[y] = value;
}
