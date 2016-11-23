#include "player.h"

Player::Player():Character("",0,0,0,0)
{
    setLvl(1);
    setExp(0);
    setExpMx(100);
    pCharge = 0;

    createInv(6);
}

Player::Player(string name, int hp, int dmg, int ac, int crit)
    :Character(name, hp, dmg, ac, crit){
    setLvl(1);
    setExp(0);
    setExpMx(100);
    pCharge = 0;

    createInv(6);
}

void Player::setLvl(int lvl){
    if(lvl > 99)
        pLvl = 99;
    else if(lvl > 0)
        pLvl = lvl;
    else
        pLvl = 0;
}

bool Player::levelup(int exp){
    bool flag = addExp(exp);
    if(flag){
        setLvl(pLvl+1);
        setHpMx(getHpMx()+10);
        setHp(getHpMx());
        setDmg(getDmg()+5);
        setAC(getAC()+3);
        setCrit(getCrit()+1);
        setExp(pExp-pExpMx);
        setExpMx(pExpMx+100);
    }
    return flag;
}

bool Player::setExp(int exp){
    if(exp > 9999)
        pExp = 9999;
    else if(exp > 0)
        pExp = exp;
    else
        pExp = 0;

    if(pExp < pExpMx)
        return false;
    else
        return true;
}

bool Player::addExp(int exp){
    if(exp > 999)
        pExp += 999;
    else if(exp > 0)
        pExp += exp;
    else
        pExp += 0;

    if(pExp < pExpMx)
        return false;
    else
        return true;
}

void Player::setExpMx(int max){
    if(max > 9999)
        pExpMx = 9999;
    else if(max > 0)
        pExpMx = max;
    else
        pExpMx = 0;
}

void Player::incCharge(){
    pCharge += 5;
    if(pCharge > 100)
        pCharge = 100;
}

bool Player::isCharged(){
    bool flag = false;

    if(pCharge > 99){
        flag = true;
    }

    return flag;
}

int Player::special(){
    int dmg = 0;
    if(isCharged()){
        dmg = getDmg()*3;
    }
    return dmg;
}

void Player::equip(int slot){
    if(slot > -1 && slot < getInv()->getCap()){
        setDmg(getDmg() + getInv()->getItem(slot).getDmg());
        setAC(getAC() + getInv()->getItem(slot).getAC());
        setCrit(getCrit() + getInv()->getItem(slot).getCrit());
        setVel(getVel() + getInv()->getItem(slot).getVel());
    }
}

void Player::dequip(int slot){
    if(slot > -1 && slot < getInv()->getCap()){
        setDmg(getDmg() - getInv()->getItem(slot).getDmg());
        setAC(getAC() - getInv()->getItem(slot).getAC());
        setCrit(getCrit() - getInv()->getItem(slot).getCrit());
        setVel(getVel() - getInv()->getItem(slot).getVel());
    }
}



