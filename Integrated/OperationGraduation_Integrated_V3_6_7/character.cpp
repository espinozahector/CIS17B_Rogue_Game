#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Character::Character(){
    //Default stats
    setHpMx(100);
    setHp(100);


    //Set default character speed
    cVel = 3;
}

Character::Character(int health){
    //Set character stats
    setHpMx(health);
    setHp(health);

    //Set default character speed
    cVel = 3;
}

Character::~Character(){
    //cInv = NULL;
}

void Character::setName(string name){
    //Set character name
    cName = name;
}

void Character::setHpMx(int max){
    if(max > 999)
        cHealthMx = 999;
    else if(max > 0)
        cHealthMx = max;
    else
        cHealthMx = 0;
}

void Character::setHp(int health){
    if (cHealth > cHealthMx)
            cHealth = cHealthMx;
    else if(health >= 0)
        cHealth = health;
    else
        cHealth = 0;

}

void Character::setDmg(int damage){
    if(damage > 999)
            cDamage = 999;
    else if(damage > 0)
        cDamage = damage;
    else
        cDamage = 0;
}

void Character::setAC(int armor){
    if(armor > 99)
            cArmor = 99;
    else if(armor > 0)
        cArmor = armor;
    else
        cArmor = 0;
}

void Character::setCrit(int crit){
    if(crit > 99)
        cCrit = 99;
    else if(crit > 0)
        cCrit = crit;
    else
        cCrit = 0;
}

void Character::createInv(int cap){
    if(cap > -1 && cap < 11){
        //Creates inventory
        //cInv = new Inv(cap);
        //Fills empty inventory
        //cInv->fill();
    }
}

void Character::setVel(int vel){
    if(vel > 10)
        cVel = 0;
    else if(vel > 0)
        cVel = vel;
    else
        cVel = 1;
}

int Character::attack(){
    //Calculates attack
    int dmg = cDamage;

    //Generates crit chance
    int crit = rand()%101;

    if(crit < cCrit){
        dmg *= 2;
    }

    //Returns damage
    return dmg;
}

int Character::getHit(int damage){
    //Calculates, sets, and returns damage on hit
    int health = cHealth;
    health -= damage;
    this->setHp(health);
    return damage;
}

int Character::attack1(Character &target){
    int dmg = this->attack();

    //Calculates target damage
    return target.getHit(dmg);
}

int Character::attack2(Character &target){
    int dmg = this->attack();

    dmg *= 2;

    //Calculates target damage
    return target.getHit(dmg);
}


int Character::heal(int heal){
    //Heals the player
    this->setHp(this->getHp()+ heal);
    return heal;
}


