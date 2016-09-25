#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inv.h"

class Player : public Character
{
    private:
        //X and Y position for character
        int xPos, yPos;

        //Player experience
        int pExp; //Current exp
        int pMxExp; //Max exp

        //Player inventory
        Inv<int> *pInv;

    public:
        Player();
        Player(int,int);
        ~Player();
};

#endif // PLAYER_H
