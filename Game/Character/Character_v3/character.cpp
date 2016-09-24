#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Character::Character()
{
    cHealth = 0;
    cDamage = 0;
    cArmor = 0;
    cCrit = 0.0;
    cName = "";
}

Character::Character(int health, int damage, int armor, float crit){
    cHealth = health;
    cDamage = damage;
    cArmor = armor;
    cCrit = crit;
}

Character::~Character(){

}

void Character::setHp(int health){
    if(health >= 0)
        cHealth = health;
    else
        cHealth = 0;

}

void Character::setDmg(int damage){
    if(damage >=0)
        cDamage = damage;
    else
        cDamage = 0;
}

void Character::setAC(int armor){
    if(armor >= 0)
        cArmor = armor;
    else
        cArmor = 0;
}

void Character::setCrit(float crit){
    if(crit >=0)
        cCrit = crit;
    else
        cCrit = 0.0;
}

int Character::attack(){
    srand(time(0));
    int dmg = cDamage;
    int crit = rand()%101; //picks a random whole number

    if(crit < cCrit){
        dmg *= 1.2;
    }
    return dmg;
}

void Character::calcDmg(int damage){
    int health = cHealth;

    //damage is reduced by the level of the armor
    health -= (damage - cArmor);

    setHp(health);
}

void Character::attackChar(Character &target){

    cout << cName <<  " attacks and deals " << cDamage
         << " damage to " << target.getName() << endl;

    //calculates the damage target character is dealt
    target.calcDmg(this->attack());
}

void Character::setName(string name){
    cName = name;
}
