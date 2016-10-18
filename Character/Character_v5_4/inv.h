#ifndef INV_H
#define INV_H

#include "item.h"

//Inventory class
class Inv
{
    private:
        //Variables
        int iCap;       //Inventory capacity
        int iSize;      //Inventory size
        Item *stock;    //Inventory stock

        //Functions
        void sort(int); //Sorts inv

    public:
        //Constructors
        Inv();
        //Param(Capacity)
        Inv(int);
        ~Inv();

        //Inv capacity get/set
        void setCap(int);
        int getCap(){return iCap;}

        //Inv size get
        int getSize(){return iSize;}

        //Inventory
        bool addItem(Item);     //Add item
        bool pullItem(int);     //Pulls then sorts item(slot)
        bool remItem(int);      //Remove item(slot)
        Item getItem(int);      //return item(slot)
        void genItems(int);     //Generates random items(scaling)
        void fill();            //Fills empty stock
};

#endif // INV_H
