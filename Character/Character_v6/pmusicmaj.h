#ifndef PMUSICMAJ_H
#define PMUSICMAJ_H

#include "player.h"

//Music major player class
class pMusicMaj : public Player
{
private:
    const string PCLASS = "Triangle Guy";
    //Item name generator(slot)
    //Assigns/returns the string based on slot value
    //Item name is related to slot ie) glasses for cs major helm.
    string genName(int);

public:
    //Constructor for player
    //Assigns preset values to player constructor call
    //ex) pJock() : Player("Jock", 100, 10, 10, 10)
    //Balance values as you see fit
    //Creates Inv(cap=6) in constructor
    pMusicMaj(string);

    //Returns class name
    string getClass(){return PCLASS;}

    //Sets item into the inventory
    //item id designates the inv slot
    //Calls itemName(int) to append name to item's current name
    //Returns true if successful
    bool grabItem(Item);

    //Player attack functions
    //Calc/return dmg on character
    //See character class attack1() as an example
    int attack1(Character&);
    int attack2(Character&);
};

#endif // PMUSICMAJ_H
