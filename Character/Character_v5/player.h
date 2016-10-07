#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inv.h"

//Player class
class Player : public Character
{
    private:
        int pExp;           //Player current exp
        int pExpMx;         //Player Max exp

        Inv *pInv;          //Player equipment

    public:
        //Constructors
        Player();
        //Param(name,health,damage,armor,crit)
        Player(string,int,int,int,int);
        ~Player();

        //Experience
        void addExp(int);   //Add exp
        int getExp();       //Return exp

        //Max Experience
        void setExpMx(int); //Sets max exp
        void addExpMx(int); //Increases max exp
        int getExpMx();     //Returns max exp

        //Inventory
        void createInv(int);//Creates Inventory(capacity)

        //GUI Functions
        void render();        //Renders Player

        static const int PHEIGHT = 0;  //Player image height
        static const int PWIDTH = 0;   //Player image width

};

#endif // PLAYER_H
