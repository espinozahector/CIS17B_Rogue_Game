#include <ctime>
#include <cstdlib>
#include "inv.h"

//Constructors
Inv::Inv()
{
    setCap(1);
    stock = new Item[iCap];
    fill();

}
Inv::Inv(int cap)
{
    setCap(cap);
    stock = new Item[iCap];
    fill();
}
Inv::~Inv()
{
    delete [] stock;
    stock = NULL;
}

void Inv::setCap(int cap){
    //if the cap is 1-10
    if(cap > 0 && cap < 11)
        //Set cap
        iCap = cap;
    else
        iCap = 1;
}


//Inventory
bool Inv::setItem(Item item, int slot){
    //If slot is not within range
    if(slot < 0 && slot > iCap-1)
        return false;
    else{
        //Set item
        stock[slot] = item;
        return true;
    }
}

Item Inv::getItem(int slot){
    //If slot is not within range
    if(slot < 0 && slot > iCap-1){
        //Return blank
        Item blank;
        return blank;
    }
    else
        //Return item
        return stock[slot];
}

Item Inv::popItem(int slot){
    Item blank;
    //If slot is not within range
    if(slot < 0 && slot > iCap-1){
        return blank;
    }
    else{
        //Return and remove item
        Item item = stock[slot];
        remItem(slot);
        return item;
    }
}

bool Inv::remItem(int slot){
    //If slot is not within range
    if(slot < 0 && slot > iCap-1)
        return false;
    else{
        //Remove item
        Item blank;
        stock[slot] = blank;
        return true;
    }
}

void Inv::genInv(int scale){
    //Fills inventory with random items
    for(int i = 0 ;i < iCap; i++){
        Item item;
        item.genStats(scale);
        stock[i] = item;
    }
}

void Inv::fill(){
    //Fills inventory with empty items
    Item blank;
    for(int i = 0; i < iCap; i++){
        stock[i] = blank;
    }
}



