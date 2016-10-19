#ifndef EFOOD_H
#define EFOOD_H

#include "character.h"

class eFood : public Character
{
    private:
        int exp;    //Enemy exp worth

    public:
        //Param(player level)
        //Generates and scales stats based on the player lvl
        //Character constructor is empty
        //  *Set stats in constructor
        //  *Balance stats as necessary
        //Calls genInv(player lvl) for item creation
        eFood(int);

        //Sets exp worth(exp)
        //Accept values 0-999
        void setExp(int);
        int getExp(){return exp;}

        //Enemy attack functions
        //Calc/return dmg on character
        //See character class attack1() as an example
        int attack1(Character&);
        int attack2(Character&);

        //Generates a random number and returns an item based
        //on the result
        //Ex) See Char_v5 enemy.dropLoot()
        Item drop();
};

#endif // EFOOD_H
