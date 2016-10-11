/* 
 * File:   Room.h
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:25 PM
 * Purpose: 
 */

#ifndef ROOM_H
#define ROOM_H

#include "Map.h"

class Room : public Map
{
private:
    int rRows;
    int rCols;
    int xLoc;
    int yLoc;
public:
    Room();
    Room(int, int, int, int);
    ~Room();
    int getRRows() {return rRows;}
    int getRCols() {return rCols;}
    void insRoom(int,int);          //setting room array to level locations
    void prntRoom();
    void prntRoom(int,int);
};

#endif /* ROOM_H */

