#include "pcsmaj.h"

pCsMaj::pCsMaj(string name):
    Player(name, 90, 15, 2, 6)
{

}

bool pCsMaj::grabItem(Item item){
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

int pCsMaj::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int pCsMaj::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}


string pCsMaj::genName(int slot){
    string name;
    switch(slot){
        case 0:
            name = "Glasses";
            break;
        case 1:
            name = "Hoodie";
            break;
        case 2:
            name = "Jeans";
            break;
        case 3:
            name = "Sneakers";
            break;
        case 4:
            name = "Computer";
            break;
        case 5:
            name = "Mouse";
            break;
        default:
            name = "";
            break;
    }
    return name;
}
