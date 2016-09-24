#include "character.h"
#include <cstdlib>
#include <ctime>

Character::Character()
{
    cHealth = 0;
    cDamage = 0;
    cArmor = 0;
    cCrit = 0.0;
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

void Character::setCrit(int crit){
    if(crit >=0)
        cCrit = crit;
    else
        cCrit = 0;
}

int Character::attack(){
    srand(time(0));
    int dmg = cDamage;
    int crit = rand()%101;

    if(crit < cCrit){
        dmg *= 1.2;
    }

    return dmg;
}

void Character::calcDmg(int damage){
    int health = cHealth;
    health -= (damage - cArmor);
    setHp(health);
}
