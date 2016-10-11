/*
 * File:   Map.h
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:07 PM
 * Purpose:
 */

#ifndef LEVEL_H
#define LEVEL_H

#include "Cols.h"
class Level : public Cols
{
private:
    int  xStart;        // X location of starting room
    int yStart;         // Y location of starting room
    int numRoom;        // Number of rooms to create
    vector<int> RoomX;  // Stores the X location of rooms (parallel to RoomY)
    vector<int> RoomY;  // Stores the Y location of rooms (parallel to RoomX)
public:
    Level();                          // Default constructor
    Level(int,int);                   // Constructor with two parameters
    ~Level();                         // Destructor
    void setRoom(int,int);          // Sets room to true
    void setStrt(int,int);          // Sets the start of the level
    int getXStrt() {return xStart;} // Get X position of start
    int getYStrt() {return yStart;} // Get Y position of start
    void bldLevel();                // Builds the level / room locations
    void findEnd();                 // Finds farthest location from center
    int getNRooms() {return numRoom;}
};


#endif // LEVEL_H
