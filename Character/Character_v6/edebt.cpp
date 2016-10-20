#include "edebt.h"

eDebt::eDebt(int level):Character(){
    setName("Debt Ghost");
    setHpMx(20+(20*level/3));
    setHp(getHpMx());
    setDmg(10+(5*level/3));
    setAC(2+(2*level/3));
    setCrit(5+(5*level/3));
    setExp(5 + (10*level/3));

    createInv(10);
    getInv()->genInv(level);
}

void eDebt::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int eDebt::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int eDebt::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

Item eDebt::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}


