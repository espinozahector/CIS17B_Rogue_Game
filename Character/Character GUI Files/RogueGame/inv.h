#ifndef INV_H
#define INV_H

#include "item.h"

//Inventory class
class Inv
{
    private:
        //Variables
        int iCap;       //Inventory capacity
        Item *stock;    //Inventory stock

    public:
        //Constructors
        Inv();
        //Param(Capacity)
        Inv(int);
        ~Inv();

        //Inv capacity get/set
        void setCap(int);
        int getCap(){return iCap;}

        //Inventory
        bool setItem(Item, int);//Adds item to inv slot
        Item getItem(int);      //return item(slot)
        Item popItem(int);      //Returns and removes item(slot)
        bool remItem(int);      //Remove item(slot)
        void genInv(int);       //Generates random inv(scaling)
        void fill();            //Fills inventory with empty items
};

#endif // INV_H
