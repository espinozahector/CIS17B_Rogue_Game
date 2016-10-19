#include "player.h"

Player::Player():Character("",0,0,0,0)
{/*
    setLvl(1);
    setExp(0);
    setExpMx(100);
    pCharge = 0;
*/
}

Player::Player(string name, int hp, int dmg, float ac, int crit)
    :Character(name, hp, dmg, ac, crit)
{/*
    setLvl(1);
    setExp(0);
    setExpMx(100);
    pCharge = 0;
*/
}
