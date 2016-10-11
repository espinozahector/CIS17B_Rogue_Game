#ifndef INV_H
#define INV_H

#include "item.h"

//Inventory class
class Inv
{
    private:
        int iCap;       //Inventory capacity
        int iSize;      //Inventory size
        Item *stock;    //Inventory stock

        void pStart();  //Fills beginning player stock
        void eFill(int);//Fills enemy stock for random loot drop

    public:
        //Constructors
        Inv();
        //Param(Player Level)
        Inv(int);
        //Param(Item array)
        Inv(Item&);
        ~Inv();

        //Inv capacity get/set
        void setCap(int);
        int getCap();

        //Inv size get
        int getSize();

        //Inventory
        void addItem(Item);     //Add item
        Item swapItem(Item);    //Swap item
        Item getItem(int);      //return item(Player Level)
        Item randItem(int, int);// generate a random item(Player Level, Equipment Slot)
        int randStat(int);      // generate random stat for random items(Player Level)



};

#endif // INV_H
