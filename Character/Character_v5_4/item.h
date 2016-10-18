#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ctime>

using namespace std;

//Item class
class Item
{
    private:
        //Variables
        int xPos, yPos; //Item coordinates

        int itemID;     //Item identification #
                        //(0=head,1=torso,2=legs,
                        //3=feet,4=left weapon,
                        //5=right weapon,6=empty)
        int iDmg;       //Item damage
        int iArmor;     //Item Armor
        int iCrit;      //Item crit
        int iVel;       //Item speed buff (velocity)
        string iName;   //Item name

        //Functions
        int genDmg(int);//Generate dmg(id)
        int genAc(int); //Generate armor(id)
        int genCrit(int);//Generate crit(id)
        int genVel(int);   //Generates velocity(id)
        //Generate item name prefix
        string genPrefix();
        //Generate item name suffix
        string genSuffix();

    public:
        //Constructors
        //default constructor is empty inventory placeholder item
        Item();
        //Param(ID, name, dmg, armor, crit, spd)
        Item(int, string, int, int, int, int);

        //Item ID get/set
        void setID(int);
        int getID(){return itemID;}

        //Item name get/set
        void setName(string);
        string getName(){return iName;}

        //Item damage get/set
        void setDmg(int);
        int getDmg(){return iDmg;}

        //Item armor get/set
        void setAC(int);
        int getAC(){return iArmor;}

        //Item crit get/set
        void setCrit(int);
        int getCrit(){return iCrit;}

        //Velocity get/set
        void setVel(int);
        int getVel(){return iVel;}

        //Generate random stats(scaling)
        void genStats(int);

        //render item
        void render();
};
#endif // ITEM_H
