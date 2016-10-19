#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inv.h"

/*Player class
 * This class acts as the primary controller from the player
 *

*/
class Player : public Character
{
    private:
        int pLvl;           //Player level
        int pExp;           //Player current exp
        int pExpMx;         //Player max exp

        int pCharge;       //Player charge val for special attack

    public:
        //Constructors
        Player();
        //Param(name,health,damage,armor,crit)
        Player(string, int, int, float, int);
        ~Player();

        //Level functions
        //Sets level(value)
        //Level must be 0-99
        void setLvl(int);           //Sets lvl
        int getLvl(){return pLvl;}  //Gets lvl

        //Calc player stat increase
        //Ex) See Char_v5 enemy.scaleUp()
        //Resets exp to currentExp - maxExp for exp carry
        void levelup();

        //Experience
        //Sets exp(value)
        //Allow values 0-999
        //returns true if the exp exceeds maxExp
        bool setExp(int);//Set exp and flags lvl up
        //Adds exp(value)
        //Returns true if exp exceeds maxExp
        bool addExp(int);//Add exp and flags lvl up
        int getExp(){return pExp;}       //Returns exp

        //Max Experience
        void setExpMx(int);     //Sets max exp(0-9999)
        int getExpMx(){return pExpMx;}     //Returns max exp

        //Charge
        int getCharge(){return pCharge;}//Returns special charge
        //Increases special charge by a set amount of 5
        //Special charge cannot exceed max charge(100)
        void incCharge();
        //Returns true once the charge reaches a set amount of 100
        bool isCharged();   //Returns charge flag
        //Calc/returns special attack
        //Does not run if isCharged() returns false
        //Resets charge to 0 if ran
        int special();
};

#endif // PLAYER_H
