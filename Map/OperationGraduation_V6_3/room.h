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
    bool *doors;     //stores what doors are where (index 0 = top, index 1 = right, index 2 = bottom, index 3 = left)
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
    void setDoors(bool *);          // Sets the doors in current room
    bool getDoors() {return doors;} // Gets the doors of the current room
};

#endif // ROOM_H
