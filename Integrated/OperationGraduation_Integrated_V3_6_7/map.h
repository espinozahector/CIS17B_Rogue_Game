/*
 * File:   Map.h
 * Author: Victor Alcaraz
 * Created on September 27, 2016, 12:42 PM
 * Purpose:
 */

#ifndef MAP_H
#define MAP_H

#include "Room.h"


class Map : public Room
{
private:
    Room **roomMap;
public:
    Map();
    Map(int,int);
    ~Map();
    void prntAll();
    void prntSel();      //prints the selected room at x,y
    Room *getRoom(int,int);
    void DoorsChk();
    void findEnd();                   // Finds farthest location from center
    void setBossRoom();
    int farX;
    int farY;

    int getFarX() {return farX;}
    int getFarY() {return farY;}
};

#endif // MAP_H
