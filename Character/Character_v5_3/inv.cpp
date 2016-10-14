#include <ctime>
#include <cstdlib>
#include "inv.h"

Inv::Inv()
{
    setCap(6);
    stock = new Item[iCap];
    pStart();

}
Inv::Inv(int lvl)
{
    setCap(6);
    stock = new Item[iCap];
    eFill(lvl);
}
Inv::~Inv()
{
    delete [] stock;
    stock = NULL;
}
Inv::pStart()
{
    stock[0] = new Item();


}
Inv::eFill(int lvl)
{

}
int Inv::getSize()
{
    int cap = getCap();
    int tally = 0;
    for (int i = 0; i < cap-1; i++)
    {
        if(stock[i.itemID] < cap)
        {
            tally++;
        }
    }
    return tally;
}
Item Inv::getItem(int id)
{
    int cap = getCap();
    if(id <= 0 && id > cap)
    {
        return stock[id];
    }
}
Item Inv::randItem(int lvl, int slot)
{
    int tempDmg = randStat(lvl);
    int tempAC = randStat(lvl);
    int tempCrit = randStat(lvl);
    int tempSpd = randStat(lvl);
    Item rI = new Item(slot, "sword", tempDmg, tempAC, tempCrit, tempSpd);
    return rI;
}
int Inv::randStat(int lvl)
{
    srand(time(NULL));
    int n = 1;
    int stat = rand()%(n*lvl)+(2*(n*lvl));
    if(stat > 99)
    {
        stat = 99;
    }
    return stat;
}
