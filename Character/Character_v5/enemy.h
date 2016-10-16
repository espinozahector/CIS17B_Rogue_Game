#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"
#include "inv.h"

class Enemy : public Character
{
    private:
        int eExp;           //Enemy experience worth

        const float SCALE = 0.3;   //Enemy stat scaling

        //Movement functions
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void idle();

    public:
        //Constructor
        Enemy();
        //*Param(name, health, dmg, armor, crit, exp)
        Enemy(string, int, int, int, int, int);
        ~Enemy();

        //Exp get/set
        void setExp(int);
        int getExp();

        //Items
        Item dropLoot();        //Returns item drop

        //Scale enemy stats
        void scaleUp();
        void scaleDown();

        //Combat functions
        int skill_1();  //Primary skill
        int skill_2();  //Secondary skill
        void track(Player&);   //Tracking state

        //Render function
        void render();

};

#endif // ENEMY_H
