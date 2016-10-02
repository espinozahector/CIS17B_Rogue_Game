#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Character::Character(){
    //Default stats
    setName("");
    setHp(0);
    setDmg(0);
    setAC(0);
    setCrit(0);

    //Set player position
    cXpos = 0;
    cYpos = 0;

    //Set player speed
    cVel = 3;

    setCoor(cXpos,cYpos);
}

Character::Character(int health, int damage, int armor, int crit){
    //Set player stats
    setName("");
    setHp(health);
    setDmg(damage);
    setAC(armor);
    setCrit(crit);

    //Set player position
    cXpos = 0;
    cYpos = 0;

    //Set player speed
    cVel = 3;

    setCoor(cXpos,cYpos);
}

Character::Character(string name, int health, int damage, int armor, int crit){
    //Set character stats
    setName(name);
    setHp(health);
    setDmg(damage);
    setAC(armor);
    setCrit(crit);

    //Set player position
    cXpos = 0;
    cYpos = 0;

    //Set player speed
    cVel = 3;

    setCoor(cXpos,cYpos);
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

void Character::setCoor(int x, int y){
    setX(x);
    setY(y);
}

int Character::attack(){
    //Calculates attack
    srand(time(0));
    int dmg = cDamage;
    int crit = rand()%101;

    if(crit < cCrit){
        dmg *= 1.5;
    }

    return dmg;
}

int Character::getHit(int damage){
    //Calculates damage on hit
    int health = cHealth;
    int dmg = damage - cArmor;
    health -= dmg;
    setHp(health);
    return dmg;
}

void Character::attackChar(Character &target){
    //Outputs and calculates target damage
    cout << cName <<  " attacks and deals " << target.getHit(this->attack())
         << " damage to " << target.getName() << endl;
}

void Character::setName(string name){
    cName = name;
}
