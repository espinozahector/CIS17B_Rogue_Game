#include "item.h"


//Constructors
Item::Item()
{
    iName = "";

    iDmg = 0;
    iArmor = 0;
    iCrit = 0;
    iVel = 0;
    itemID = -1;     //Empty item Id
}

Item::Item(int id, string name, int dmg, float ac, int crit, int vel){
    setName(name);  //Set item name
    setID(id);      //Set item id
    setDmg(dmg);    //Set item dmg
    setAC(ac);      //Set item armor
    setCrit(crit);  //Set item crit
    setVel(vel);    //Set item velocity buff
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

void Item::setAC(float ac){
    if(ac > .99)
        iArmor = .99;
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
    //Generates item id
    int id = (rand()%7) - 1;
    setID(id);

    //If the id isn't -1
    if(id != -1){
        //Generate name
        string name = genPrefix() + " " + genSuffix();
        setName(name);
    }

    //Generate dmg
    int dmg = genDmg(id);
    setDmg(dmg + (dmg*(scale/3)));

    //Generate armor
    float ac = static_cast<float>(genAc(id))/100;
    setAC(ac + (ac*(scale/3)));

    //Generate crit
    int crit = genCrit(id);
    setCrit(crit + (crit*(scale/3)));

    //Generate movement speed
    setVel(genVel(id));
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
string Item::genPrefix()
{
    string prefix = "";
    int pick = rand()%12;
    switch (pick) //prefix possibilities
    {
        case 0:
            prefix = "Ancient";
            break;
        case 1:
            prefix = "Chaotic";
            break;
        case 2:
            prefix = "Colossal";
            break;
        case 3:
            prefix = "Deadly";
            break;
        case 4:
            prefix = "Explosive";
            break;
        case 5:
            prefix = "Lucky";
            break;
        case 6:
            prefix = "Menacing";
            break;
        case 7:
            prefix = "Sturdy";
            break;
        case 8:
            prefix = "Trusty";
            break;
        case 9:
            prefix = "Terrifying";
            break;
        case 10:
            prefix = "Hilarious";
        default:
            prefix = "";
            break;
    }
    return prefix;
}

string Item::genSuffix()
{
    string suffix = "";
    int pick = rand()%12;
    switch (pick) //suffix possibilities
    {
        case 0:
            suffix = "Alacrity";
            break;
        case 1:
            suffix = "Corrupted";
            break;
        case 2:
            suffix = "Devastation";
            break;
        case 3:
            suffix = "Doom";
            break;
        case 4:
            suffix = "Foreboding";
            break;
        case 5:
            suffix = "Frightful";
            break;
        case 6:
            suffix = "Painful";
            break;
        case 7:
            suffix = "Powerful";
            break;
        case 8:
            suffix = "Prophetic";
            break;
        case 9:
            suffix = "Ruined";
            break;
        case 10:
            suffix = "Hilarity";
        default:
            suffix = "";
            break;
    }
    return suffix;
}
