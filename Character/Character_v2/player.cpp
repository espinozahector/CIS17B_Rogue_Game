#include "player.h"

Player::Player()
{
    pInv = new Inv<int>;
}

Player::Player(int x, int y){
    xPos = x;
    yPos = y;
}

Player::~Player(){
    pInv = NULL;
}
