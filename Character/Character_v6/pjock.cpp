#include "pjock.h"

pJock::pJock(string name):
    Player(name, 110, 10, 7, 2)
{

}

bool pJock::grabItem(Item item){
    bool flag = false;

    //If item isn't blank
    if(item.getID() > -1){
        //Appened specific item name
        item.setName(item.getName()+" "
                     +genName(item.getID()));
        //Add item to inventory
        getInv()->setItem(item, item.getID());
        //Set item stats
        equip(item.getID());
        //Flag item success
        flag = true;
    }

    //Return flag
    return flag;
}

int pJock::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int pJock::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

string pJock::genName(int slot){
    string name;
    switch(slot){
        case 0:
            name = "Helmet";
            break;
        case 1:
            name = "Padded Jersey";
            break;
        case 2:
            name = "Thigh pads";
            break;
        case 3:
            name = "Cleats";
            break;
        case 4:
            name = "Bat";
            break;
        case 5:
            name = "Tackle Dummy";
            break;
        default:
            name = "";
            break;
    }
    return name;
}
