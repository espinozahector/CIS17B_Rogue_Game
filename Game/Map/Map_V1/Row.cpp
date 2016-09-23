/* 
 * File:   Map.cpp
 * Author: Victor Alcaraz
 * Created on September 22, 2016, 10:06 PM
 * Purpose: 
 */

#include "Row.h"


Row::Row()
{    
    rows = 9;
    table = new bool[rows];
    
    for(int i = 0; i < rows; i++)
    {
        table[i] = 0;
    }
}

Row::Row(int newRow)
{
    rows = newRow;
    table = new bool[rows];
    
    for(int i =0; i < rows; i++)
    {
        table[i] = 0;
    }
}

void Row::setEl(int y) {
    table[y] = 1;
}

Row::~Row()
{
    delete [] table;
}