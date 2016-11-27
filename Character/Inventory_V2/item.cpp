#include "item.h"
#include <iostream>
using namespace std;

Item::Item()
{
}
Item::Item(int id, string n, int d, int a, int c)
{
    setID(id);
    setName(n);
    setDmg(d);
    setAC(a);
    setCrit(c);
}

//Item ID get/set
void Item::setID(int id)
{
    itemID = id;
}
int Item::getID()
{
    return itemID;
}

//Item name get/set
void Item::setName(string n)
    {
        iName = n;
    }
string Item::getName()
{
    return iName;
}

//Item damage get/set
void Item::setDmg(int d)
{
    iDamage = d;
}
int Item::getDmg()
{
    return iDamage;
}

//Item armor get/set
void Item::setAC(int a)
{
    iArmor = a;
}
int Item::getAC()
{
    return iArmor;
}

//Item crit get/set
void Item::setCrit(int c)
{
    iCrit = c;
}
int Item::getCrit()
{
    return iCrit;
}

void Item::display()
{
   cout << "Name: " << getName() << endl;
   cout << "DMG: " << getDmg() << endl;
   cout << "Armor: " << getAC() << endl;
   cout << "Crit Chance Boost: " << getCrit() << endl;
}
