#include <ctime>
#include <cstdlib>
#include "inv.h"

//Constructors
Inv::Inv()
{
    setCap(1);
    iSize = 0;
    stock = new Item[iCap];
    fill();

}
Inv::Inv(int cap)
{
    setCap(cap);
    iSize = 0;
    stock = new Item[iCap];
    fill();
}
Inv::~Inv()
{
    delete [] stock;
    stock = NULL;
}

//Sets
void Inv::setCap(int cap){
    if(cap > 0 && cap < 11)
        iCap = cap;
    else
        iCap = 0;
}

//Inventory
bool Inv::addItem(Item item){
    if(iSize >= iCap)
        return false;
    else{
        stock[iSize] = item;
        iSize++;
    }
}

bool Inv::pullItem(int slot){
    //Removes then sorts inv
    //Enemy use
    if(slot < 0 && slot > iSize)
        return false;
    else{
        Item blank;
        stock[slot] = blank;
        sort(slot);
        iSize--;
        return true;
    }
}

bool Inv::remItem(int slot){
    //Removes item
    //Player use
    if(slot < 0 && slot > iSize)
        return false;
    else{
        Item blank;
        stock[slot] = blank;
        return true;
    }
}

Item Inv::getItem(int slot){
    return stock[slot];
}

void Inv::fill(){
    //Fills inventory with empty items
    Item blank;
    for(int i = 0; i < iCap; i++){
        stock[i] = blank;
    }
}

void Inv::genItems(int scale){
    //Fills inventory with random items
    for(int i = 0 ;i < iCap; i++){
        Item item;
        item.genStats(scale);
        stock[i] = item;
    }
}


//Private functions
void Inv::sort(int slot){
    //Does a simple sort for inv
    for(int i = slot; i > iCap-1; i++){
        stock[i] = stock[i+1];
    }
}


