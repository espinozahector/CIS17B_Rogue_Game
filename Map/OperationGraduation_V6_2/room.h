/*
 * File:   Room.h
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:25 PM
 * Purpose:
 */

#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <utility>
#include "Level.h"


class Room : public Level
{
private:
    int rRows;
    int rCols;
    int xLoc;
    int yLoc;
    Row **room;
    int size;
public:
    Room();
    Room(int, int, int, int);  // for building room instances
    Room(int, int);
    ~Room();
    int getRRows() {return rRows;}
    int getRCols() {return rCols;}
    void bldRoom();
    void prntRoom();
    void setLoc(int,int);
    int getXLoc() {return xLoc;}
    int getYLoc() {return yLoc;}
    bool getRoomVal(int,int);
    void startRoom();
};

#endif // ROOM_H
