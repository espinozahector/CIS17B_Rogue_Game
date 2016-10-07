#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "inv.h"

class Enemy : public Character
{
    private:
        int eXpos, eYpos;   //Enemy coordinates
        int eExp;           //Enemy experience worth
        Inv *loot;          //Enemy loot drop

    public:
        //Constructor
        Enemy();
        //*Param(x-coor, y-coor, name, health, dmg, armor, crit)
        Enemy(int, int, string, int, int, int, int);
        ~Enemy();

        //X-coor get/set
        void setX(int);
        int getX();

        //Y-coor get/set
        void setY(int);
        int getY();

        //Exp get/set
        void setExp(int);
        int getExp();

        //Items
        void createInv(int);    //Creates inv
        Item dropLoot();        //Returns item drop

        //Render function
        void render();

};

#endif // ENEMY_H
