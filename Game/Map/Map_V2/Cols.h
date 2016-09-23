/* 
 * File:   Cols.h
 * Author: Victor Alcaraz
 * Created on September 22, 2016, 10:35 PM
 * Purpose: 
 */

#ifndef COLS_H
#define COLS_H

#include "Row.h"

class Cols
{
private:
    int szCols;
    int szRows;
    int xCoord;
    int yCoord;
    int xStart;
    int yStart;
    int numRoom;
    Row **map;
    vector<int> RoomX;
    vector<int> RoomY;
public:
    Cols();
    Cols(int,int);
    ~Cols();
    int getCols() {return szCols;}
    int getRows() {return szRows;}
    bool getData(int,int);
    void setRoom(int,int);
    void setStrt(int,int);
    int getXStrt() {return xStart;}
    int getYStrt() {return yStart;}
    void buildMap();
};

#endif /* COLS_H */