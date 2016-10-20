#include "eexam.h"


eExam::eExam(int level):Character(){
    setName("Exam Fiend");
    setHpMx(30+(20*level/3));
    setHp(getHpMx());
    setDmg(8+(8*level/3));
    setAC(10+(5*level/3));
    setCrit(5+(5*level/3));
    setExp(8 + (10*level/3));

    createInv(10);
    getInv()->genInv(level);
}

void eExam::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

int eExam::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int eExam::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 1.5;

    //Calculates target damage
    return target.getHit(dmg);
}

Item eExam::drop(){
    //Generates index
    int index = rand()%getInv()->getCap();
    //Drop random items
    return getInv()->getItem(index);
}
