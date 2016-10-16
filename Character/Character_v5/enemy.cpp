#include "enemy.h"
#include <ctime>

Enemy::Enemy():Character("",0,0,0,0){
    //Set enemy exp and inv
    setExp(0);
    createInv(0);
}

Enemy::Enemy(string name, int hp, int dmg, int ac, int crit, int exp)
    :Character(name, hp, dmg, ac, crit){
    //Set enemy exp and inv
    setExp(exp);
    createInv(5);
}


Enemy::~Enemy(){

}

void Enemy::setExp(int exp){
    if(exp > 999)
        eExp = 999;
    else if(exp > 0)
        eExp = exp;
    else
        eExp = 0;
}

Item Enemy::dropLoot(){
    int index = rand()%getInv()->getCap();  //Generates index
    return getInv()->getItem(index);        //Returns random item
}

void Enemy::scaleUp(){
    //Scales stats up
    setHpMx(getHpMx()+(getHpMx()*SCALE));
    setDmg(getDmg()+(getDmg()*SCALE));
    setAC(getAC()+(getAC()*SCALE));
    setCrit(getCrit()+(getCrit()*SCALE));
}

void Enemy::scaleDown(){
    //Scales stats down
    setHpMx(getHpMx()-(getHpMx()*SCALE));
    setDmg(getDmg()-(getDmg()*SCALE));
    setAC(getAC()-(getAC()*SCALE));
    setCrit(getCrit()-(getCrit()*SCALE));
}

int Enemy::skill_1(){
   //Normal attack
    return attack();
}

int Enemy::skill_2(){
    //Secondary attack
    return attack()*1.5;
}

void Enemy::track(Player& player){
    //If the player isnt dead
    if(!player.isDead()){
        int action = rand()%10;

        if(action > 1){
            //Move towards player coordinates
            if(this->getY() > player.getY()){
                //Player above
                moveUp();
            }
            else if(this->getY() < player.getY()){
                //Player below
                moveDown();
            }

            if(this->getX() > player.getX()){
                //Player left
                moveLeft();
            }
            else if(this->getX() < player.getX()){
                //Player right
                moveRight();
            }
        }
        else{
            //Go idle
            idle();
        }
    }
    else{
        //Become idle
        idle();
    }

}

void Enemy::render(){
    //Render enemy
}

void Enemy::moveUp(){
    //Sets the y -= vel
    setY(this->getY() - this->getVel());
}

void Enemy::moveDown(){
    //Sets the y += vel
    setY(this->getY() + this->getVel());
}

void Enemy::moveLeft(){
    //Sets the x -= vel
    setX(this->getX() - this->getVel());
}

void Enemy::moveRight(){
    //Sets the x += vel
    setX(this->getX() + this->getVel());
}

void Enemy::idle(){
    //Enemy wanders randomly
    srand(time(0));
    int direction = rand()%5;

    if(direction == 0){
        //Move enemy up
        moveUp();
    }
    else if(direction == 1){
        //Move enemy down
        moveDown();
    }
    else if(direction == 2){
        //Move enemy left
        moveLeft();
    }
    else if(direction == 3){
        //Move enemy right
        moveRight();
    }
}

