#ifndef PJOCK_H
#define PJOCK_H

#include "player.h"

//Jock player class
class pJock : public Player
{
    private:
        //Item name generator(slot)
        //Assigns/returns the string based on slot value
        //Item name is related to slot ie) glasses for cs major helm.
        string itemName(int);

    public:
        //Constructor
        //Assigns preset values to player constructor call
        //ex) pJock() : Player("Jock", 100, 10, 10, 10)
        //Balance values as you see fit
        //Creates Inv(cap=6) in constructor
        pJock();

        //Sets item into the inventory
        //item id designates the inv slot
        //Calls itemName funct to append name to item's current name
        //Returns true if successful
        bool grabItem(Item);

        //Player attack functions
        //Calc/return dmg on character
        //See character class attack1() as an example
        int attack1(Character&);
        int attack2(Character&);
};

#endif // PJOCK_H
