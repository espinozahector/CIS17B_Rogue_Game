#include "player.h"

Player::Player()
{
    setLvl(1);
    setExp(0);
    setExpMx(100);
}
//check for level up, and call level up function when satisfied
void Player::checkLvl()
{
    if (pExp >= pExpMx)
    {
        lvlUp();
    }
}
//increase level, Max Exp, health, damage, and armor
void Player::lvlUp()
{
    setLvl(getLvl() += 1);
    setHp(getHp() += 5);
    setDmg(getDmg() += 1);
    setAC(getAC() += 1);
    setExpMx(getExpMx() += (getLvl() * 100));
}

