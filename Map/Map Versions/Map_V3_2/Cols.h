/* 
 * File:   Cols.h
 * Author: Hector and victor
 * Created on September 24, 2016
 * Purpose: 
 */

#ifndef COLS_H
#define COLS_H

#include "Row.h"

class Cols : public Row
{
private:
    int szCols;         // size of columns
    int szRows;         // size of rows
public:
    Row **level;        // 2-D array to construct where rooms are
    Cols();             // Default Constructor
    Cols(int,int);      //Constructor with rows and columns parameter
    ~Cols();            //Destructor
    int getCols() {return szCols;}  // Get Column size
    int getRows() {return szRows;}  // Get Rows size
    bool getData(int,int);          // Get the data from the level array
};

#endif /* COLS_H */