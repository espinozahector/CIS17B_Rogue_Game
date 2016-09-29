#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inv.h"

//Player class
class Player : public Character
{
    private:
        int level;          //Player level
        int pXpos, pYpos;   //Player coordinates
        int pExp;           //Player current exp
        int pExpMx;         //Player Max exp

        Inv *pInv;          //Player equipment

    public:
        //Constructors
        Player();
        //Param(x-coor,y-coor,name,health,damage,armor,crit)
        Player(int,int,string,int,int,int,int);
        ~Player();

        //X coordinate set/get
        void setX(int);
        int getX();

        //Y coordinate set/get
        void setY(int);
        int getY();

        //Level
        void setLvl(int){level = amt;}      //adjust private level variable
        int getLvl(){return level;}         //retrieve private level variable
        void checkLvl();                    //check for level up
        void lvlUp();                       //increase stats on level up

        //Experience
        void setExp(int);   //set exp
        int getExp();       //Return exp

        //Max Experience
        void setExpMx(int); //Sets max exp
        int getExpMx();     //Returns max exp

        //Inventory
        void createInv(int);//Creates Inventory(capacity)

        //GUI Functions
        void render();        //Renders Player

        static const int PHEIGHT = 0;  //Player image height
        static const int PWIDTH = 0;   //Player image width

};

#endif // PLAYER_H
