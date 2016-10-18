#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Character::Character(){
    //Default stats
    setName("");
    setHpMx(0);
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
    setHpMx(health);
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
    setHpMx(health);
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

void Character::setHpMx(int max){
    if(max >=0)
        cHealthMx = max;
    else
        cHealthMx = 0;
}

void Character::setHp(int health){
    if(health >= 0)
        cHealth = health;
    else if (cHealth > cHealthMx)
        cHealth = cHealthMx;
    else
        cHealth = 0;

}

void Character::setDmg(int damage){
    if(damage >=0)
        cDamage = damage;
    else if(damage >= 999)
        cDamage = 999;
    else
        cDamage = 0;
}

void Character::setAC(int armor){
    if(armor >= 0)
        cArmor = armor;
    else if(armor >= 100)
        cArmor = 99;
    else
        cArmor = 0;
}

void Character::setCrit(int crit){
    if(crit >=0)
        cCrit = crit;
    else if(crit >=100)
        cCrit = 99;
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

    //Generates crit chance
    int crit = rand()%101;

    if(crit < cCrit){
        dmg *= 1.5;
    }

    //Returns damage
    return dmg;
}

int Character::getHit(int damage){
    //Calculates damage on hit
    int health = cHealth;
    int dmg = damage*(static_cast<float>(cArmor)/100);
    health -= dmg;
    this->setHp(health);
    return dmg;
}

void Character::attackChar(Character &target){
    //Outputs and calculates target damage
    cout << cName <<  " attacks and deals " << target.getHit(this->attack())
         << " damage to " << target.getName() << endl;
}

void Character::heal(int heal){
    //Heals the player
    this->setHp(this->getHp()+ heal);
}

void Character::setName(string name){
    cName = name;
}
