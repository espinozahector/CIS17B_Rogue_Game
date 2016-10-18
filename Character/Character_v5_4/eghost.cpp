#include "eghost.h"

EGhost::EGhost() :
    Enemy("Debt Ghost", 50, 10, 5, 5, 20)
{

}

int EGhost::skill_1(){

    return attack();
}

int EGhost::skill_2(){

    return attack()*2;
}

void EGhost::render(){

}
