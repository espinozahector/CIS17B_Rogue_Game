#include "item.h"


//Constructors
Item::Item()
{
    iDmg = 0;
    iArmor = 0;
    iCrit = 0;
    iVel = 0;
    itemID = -1;     //Empty item Id
    iName = "";

    xPos = 0;
    yPos = 0;
}

Item::Item(int id, string name, int dmg, int ac, int crit, int vel){
    setID(id);      //Set item id
    setName(name);  //Set item name
    setDmg(dmg);    //Set item dmg
    setAC(ac);      //Set item armor
    setCrit(crit);  //Set item crit
    setVel(vel);    //Set item velocity buff

    xPos = 0;
    yPos = 0;
}

//Class methods
void Item::setID(int id){
    //If the number is 0 - 6
    if(id > -1 && id < 7)
        //Set id
        itemID = id;
    else
        //Set to empty id
        itemID = -1;
}

void Item::setName(string name){
    iName = name;
}

void Item::setDmg(int dmg){
    if(dmg > 99)
        iDmg = 99;
    else if(dmg>=0)
        iDmg = dmg;
    else
        iDmg = 0;
}

void Item::setAC(int ac){
    if(ac > 99)
        iArmor = 99;
    else if(ac > 0)
        iArmor = ac;
    else
        iArmor = 0;
}

void Item::setCrit(int crit){
    if(crit > 99)
        iCrit = 99;
    else if(crit > 0)
        iCrit = crit;
    else
        iCrit = 0;
}

void Item::setVel(int vel){
    if(vel > 10)
        iVel = 10;
    else if(vel > -10)
        iVel = vel;
    else
        iVel = 0;
}

void Item::genStats(int scale){
    int id = (rand()%7) - 1;
    setID(id);

    int dmg = genDmg(id);
    setDmg(dmg + (dmg*(scale/3)));

    int ac = genAc(id);
    setAC(ac + (ac*(scale/3)));

    int crit = genCrit(id);
    setCrit(crit + (crit*(scale/3)));

    setVel(genVel(id));
}

void Item::render(){

}

//Private functions
int Item::genDmg(int id){
    int dmg = 0;
    switch (id) {
        case 0: //Head
            dmg = rand()%5;
            break;
        case 1: //Chest
            dmg = rand()%8;
            break;
        case 2: //Legs
            dmg = rand()%8;
            break;
        case 3: //Feet
            dmg = rand()%5;
            break;
        case 4: //L Weapon
            dmg = rand()%10;
            break;
        case 5: //R Weapon
            dmg = rand()%10;
            break;
        default:
            dmg = 0;
            break;
    }
    return dmg;
}

int Item::genAc(int id){
    int armor = 0;
    switch (id) {
        case 0: //Head
            armor = rand()%8;
            break;
        case 1: //Chest
            armor = rand()%11;
            break;
        case 2: //Legs
            armor = rand()%8;
            break;
        case 3: //Feet
            armor = rand()%5;
            break;
        case 4: //L Weapon
            armor = rand()%2;
            break;
        case 5: //R Weapon
            armor = rand()%2;
            break;
        default:
            armor = 0;
            break;
    }
    return armor;
}

int Item::genCrit(int id){
    int crit = 0;
    switch (id) {
        case 0: //Head
            crit = rand()%3;
            break;
        case 1: //Chest
            crit = rand()%4;
            break;
        case 2: //Legs
            crit = rand()%3;
            break;
        case 3: //Feet
            crit = rand()%2;
            break;
        case 4: //L Weapon
            crit = rand()%5;
            break;
        case 5: //R Weapon
            crit = rand()%5;
            break;
        default:
            crit = 0;
            break;
    }
    return crit;
}

int Item::genVel(int id){
    int vel = 0;
    switch (id) {
        case 0: //Head
            vel = (rand()%3)-1;
            break;
        case 1: //Chest
            vel =(rand()%4)-2;
            break;
        case 2: //Legs
            vel = (rand()%4)-1;
            break;
        case 3: //Feet
            vel = rand()%3;
            break;
        case 4: //L Weapon
            vel = (rand()%3)-1;
            break;
        case 5: //R Weapon
            vel = (rand()%3)-1;
            break;
        default:
            vel = 0;
            break;
    }
    return vel;
}
