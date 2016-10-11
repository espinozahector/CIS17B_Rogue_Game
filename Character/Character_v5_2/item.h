#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

//Item class
class Item
{
    private:
        int xPos, yPos; //Item coordinates

        int itemID;     //Item identification #
                        //(0=head,1=torso,2=legs,
                        //3=feet,4=left weapon,
                        //5=right weapon,6=empty)
        int iDamage;    //Item damage
        int iArmor;     //Item Armor
        int iCrit;      //Item crit
        int iSpd;       //Item speed buff
        string iName;   //Item name

    public:
        //Constructors
        //default constructor is empty inventory placeholder item
        Item();
        //Param(ID, name, dmg, armor, crit, spd)
        Item(int, string, int, int, int, int);

        //Item ID get/set
        void setID(int);
        int getID();

        //Item name get/set
        void setName(string);
        int getName();

        //Item damage get/set
        void setDmg(int);
        int getDmg();

        //Item armor get/set
        void setAC(int);
        int getAC();

        //Item crit get/set
        void setCrit(int);
        int getCrit();

        //render item
        void render();
};
#endif // ITEM_H
