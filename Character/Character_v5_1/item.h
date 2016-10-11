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
        int iDamage;    //Item damage
        int iArmor;     //Item Armor
        int iCrit;      //Item crit

        string iName;   //Item name

    public:
        //Constructors
        Item();
        //Param(ID, name, dmg, armor, crit)
        Item(int, string, int, int, int);

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
