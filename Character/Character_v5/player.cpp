#include "player.h"

Player::Player():Character("",0,0,0,0)
{
    //setLvl(0);
    setExp(0);
    setExpMx(0);
    setCharge(0);
    setChargeMx(0);
}

Player::Player(string name, int hp, int dmg, int ac, int crit, int expMx, int chargeMx)
    :Character(name, hp, dmg, ac, crit)
{
    //setLvl(0);
    setExp(0);
    setCharge(0);
    setExpMx(expMx);
    setChargeMx(chargeMx);

}

void Player::setExp(int exp)
{
    pExp = exp;
}

void Player::addExp(int dmg)
{
    int currentExp = pExp + dmg;
    int carryOverExp = 0;

    //Checks if player levels up
    if (currentExp >= pExpMx)
    {
        //Stores extra exp once max is reached
        carryOverExp = currentExp - pExpMx;

        //Levels up the player
        pLvl++;

        //Increases the max exp
        addExpMx();

        //Resets the pExp with carryover points
        pExp = carryOverExp;

    }
    else
    {
        //adds damage to exp
        pExp = currentExp;
    }

}

void Player::setExpMx(int expMax)
{
    pExpMx = expMax;
}

void Player::addExpMx()
{
   //Increases ExpMx by itself plus half
   pExpMx += (pExpMx / 2);
}

void Player::setCharge(int charge)
{
    pCharge = charge;
}

void Player::addCharge(int dmg)
{
    int currentCharge = pCharge + dmg;

    //Restricts value of pCharge
    if (currentCharge > pChargeMx)
    {
        pCharge = pChargeMx ;

    }
    else
    {
        //Adds dmg value to charge
        pCharge = currentCharge;
    }
}

void Player::setChargeMx(int chargeMx)
{
    pChargeMx = chargeMx;
}

int Player::baseAttack()
{
    int dmg = attack();

    //checks if special Attack can be used
    if(pCharge == pChargeMx)
    {
       dmg = specialAttack(dmg);
    }
    else
    {
        addExp(dmg);
        addCharge(dmg);
    }

    return dmg;

}

int Player::specialAttack(int dmg)
{
    //Increases damage
    dmg *= 1.3;
    addExp(dmg);

    //Resets pCharge
    pCharge = 0;

    return dmg;
}








