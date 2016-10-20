#include "efood.h"

eFood::eFood(int level):Character(){
    setName("Rotted Food");
    setHpMx(40+(30*level/3));
    setHp(getHpMx());
    setDmg(10+(10*level/3));
    setAC(0+(2*level/3));
    setCrit(5+(5*level/3));
    setExp(10 + (10*level/3));

    createInv(10);
    getInv()->genInv(level);
}

void eFood::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int eFood::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int eFood::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

Item eFood::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}
