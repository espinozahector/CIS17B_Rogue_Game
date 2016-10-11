#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inv.h"

//Player class
class Player : public Character
{
    private:
        int pLvl;           //Player level
        int pExp;           //Player current exp
        int pExpMx;         //Player max exp
        int pCharge;        //Player charge for special attack
        int pChargeMx;      //Player max charge

        Inv *pInv;          //Player equipment

    public:
        //Constructors
        Player();
        //Param(name,health,damage,armor,crit,expMx, chargeMx)
        Player(string, int, int, int, int, int, int);
        ~Player();

        //Level
        void setLvl(int);           //Sets lvl
        int getLvl(){return pLvl;}  //Gets lvl

        //Experience
        void setExp(int);                //Set exp
        void addExp(int);                //Add exp
        int getExp(){return pExp;}       //Returns exp

        //Max Experience
        void setExpMx(int);                //Sets max exp
        void addExpMx();                   //Increases max exp
        int getExpMx(){return pExpMx;}     //Returns max exp

        //Charge
        void setCharge(int);                //Sets charge
        void addCharge(int);                //Increases charge
        int getCharge(){return pCharge;}    //Returns charge

        //Max Charge
        void setChargeMx(int);                //Sets max charge
        int getChargeMx(){return pChargeMx;}  //Returns max charge


        //Attack functions
        int baseAttack();
        int specialAttack(int);

        //Inventory
        void createInv(int);//Creates Inventory(capacity)

        //GUI Functions
        void render();        //Renders Player

        static const int PHEIGHT = 0;  //Player image height
        static const int PWIDTH = 0;   //Player image width

};

#endif // PLAYER_H
