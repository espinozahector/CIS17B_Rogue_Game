/* 
 * File:   Map.h
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:07 PM
 * Purpose: 
 */

#ifndef MAP_H
#define MAP_H

#include "Cols.h"
class Map : public Cols
{
private:
    int  xStart;         // X location of starting room
    int yStart;         // Y location of starting room
    int numRoom;        // Number of rooms to create
    vector<int> RoomX;  // Stores the X location of rooms (parallel to RoomY)
    vector<int> RoomY;  // Stores the Y location of rooms (parallel to RoomX)
public:
    Map();
    Map(int,int);
    ~Map();
    void setRoom(int,int);          // Sets room to true
    void setStrt(int,int);          // Sets the start of the level
    int getXStrt() {return xStart;} // Get X position of start
    int getYStrt() {return yStart;} // Get Y position of start
    void buildMap();                // Builds the level / room locations
    //void findEnd();  
};

#endif /* MAP_H */

