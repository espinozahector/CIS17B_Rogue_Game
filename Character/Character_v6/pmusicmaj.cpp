#include "pmusicmaj.h"

pMusicMaj::pMusicMaj(string name):
    Player(name, 100, 8, 5, 4)
{

}


bool pMusicMaj::grabItem(Item item){
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

int pMusicMaj::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int pMusicMaj::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}


string pMusicMaj::genName(int slot){
    string name;
    switch(slot){
        case 0:
            name = "Marching cap";
            break;
        case 1:
            name = "Uniform";
            break;
        case 2:
            name = "Slacks";
            break;
        case 3:
            name = "Fancy Shoes";
            break;
        case 4:
            name = "Metal rod";
            break;
        case 5:
            name = "Triangle";
            break;
        default:
            name = "";
            break;
    }
    return name;
}
