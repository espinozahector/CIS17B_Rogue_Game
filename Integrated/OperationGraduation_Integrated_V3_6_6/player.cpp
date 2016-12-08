#include "player.h"
#include <ctime>
#include <QList>
#include <typeinfo>

//includes debugger
#include <QDebug>

#include "bullet.h"
#include "coinblast.h"
#include "bombbullet.h"
#include "foodbullet.h"

#include "enemy.h"
#include "enemyfood.h"
#include "enemybomb.h"
#include "enemydebt.h"

Player::Player(Map *base):Character("",0,1,1,1),QGraphicsPixmapItem()
{
    setLvl(1);
    setExp(0);
    setExpMx(100);
    pCharge = 0;

    //createInv(6);

    //set graphic
    playerx = 4;
    playery = 4;
    temp = base;
    isBoss2 = false;
    isTrap = false;

    velocity = 10;

    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;

    this->installEventFilter(this);

    direct = ' ';

    isAttacking = false;

    spriteCoordLeftRight = 0;
    spriteCoordUpDown = 0;
    spriteAttackX = 0;
    spriteAttackY = 0;

    csMajor = new QPixmap(":/Character/images/characters/cs_walking.png");
    binaryAttack = new QPixmap(":/Character/images/characters/walkingBinaryAttack.png");
    binaryStanding = new QPixmap(":/Character/images/characters/CSMajor_BinaryAttack_v3.png");

    QPixmap walking = csMajor->copy(0, 120, 60, 60);
    setPixmap(walking);

    this->timer = new QTimer;
    this->timer2 = new QTimer;

    timer->setInterval(20);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));

    timer2->setInterval(20);
    timer2->start();
    connect(timer2, SIGNAL(timeout()), this, SLOT(timerEvent2()));

    refreshStatCh();                                                //initialize statchild to player
    emit playLvlUpdate(getName(), getLvl(), getHpMx(), getExpMx()); //initialize statchild to player
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
        setExpMx(pExpMx+100);
        emit playLvlUpdate(getName(), getLvl(), getHpMx(), getExpMx()); //update statchild on levelup
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

/*void Player::equip(int slot){
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
*/
void Player::refreshStatCh()
{
    setHp(getHp() + 1); //TEST TO BE REMOVED
    //playtostat arguments: (hp, damage, armor, crit, velocity, xp, weapon charge)
    emit playToStat(getHp(),getDmg(),getAC(),getCrit(),50,getExp(),50); //VALUES OF 50 ARE TEST ONLY
}

void Player::keyPressEvent(QKeyEvent *event)
{
    bool d[4] = {0,0,0,0};

    for(int i = 0; i < 4; i++)
        d[i] = temp->getRoom(playerx,playery)->getDoors(i);

    if (!event->isAutoRepeat()){
        pressedKeys += ((QKeyEvent*)event)->key();
    }

//    if(!pressedKeys.size() >2 ){
        if (pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_Left))
        {
            spriteAttackY = 120;
            spriteAttackX = 0;
            isMovingLeft = true;
            isAttacking = true;
            emit newBullet(1);
        }
        else if (pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_Right))
        {
            spriteAttackY = 360;
            spriteAttackX = 0;
            isMovingRight = true;
            isAttacking = true;
            emit newBullet(2);
        }
        else if (pressedKeys.contains(Qt::Key_W) && pressedKeys.contains(Qt::Key_Up))
        {
            spriteAttackY = 0;
            spriteAttackX = 0;
            isMovingUp = true;
            isAttacking = true;
            emit newBullet(3);
        }
        else if (pressedKeys.contains(Qt::Key_S) && pressedKeys.contains(Qt::Key_Down))
        {
            spriteAttackY = 240;
            spriteAttackX = 0;
            isMovingDown = true;
            isAttacking = true;
            emit newBullet(4);
        }
        else if (pressedKeys.contains(Qt::Key_A) && pressedKeys.contains(Qt::Key_Space))
        {
            spriteAttackY = 120;
            spriteAttackX = 0;
            isMovingRight = true;
            isAttacking = true;
            for(int i = 1; i < 9; i++)
            {
                emit newBullet(i);
            }
        }
        else if (pressedKeys.contains(Qt::Key_D) && pressedKeys.contains(Qt::Key_Space))
        {
            spriteAttackY = 360;
            spriteAttackX = 0;
            isMovingRight = true;
            isAttacking = true;
            for(int i = 1; i < 9; i++)
            {
                emit newBullet(i);
            }
        }
        else if (pressedKeys.contains(Qt::Key_W) && pressedKeys.contains(Qt::Key_Space))
        {
            spriteAttackY = 0;
            spriteAttackX = 0;
            isMovingUp = true;
            isAttacking = true;
            for(int i = 1; i < 9; i++)
            {
                emit newBullet(i);
            }
        }
        else if (pressedKeys.contains(Qt::Key_S) && pressedKeys.contains(Qt::Key_Space))
        {
            spriteAttackY = 240;
            spriteAttackX = 0;
            isMovingDown = true;
            isAttacking = true;
            for(int i = 1; i < 9; i++)
            {
                emit newBullet(i);
            }
        }
        else if (event->key() == Qt::Key_Left)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isAttacking = true;
            emit newBullet(1);
        }
        else if (event->key() == Qt::Key_Right)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isAttacking = true;
            emit newBullet(2);
        }
        else if (event->key() == Qt::Key_Up)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isAttacking = true;
            emit newBullet(3);
        }
        else if (event->key() == Qt::Key_Down)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isAttacking = true;
            emit newBullet(4);
        }
        else if (event->key() == Qt::Key_Space)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isAttacking = true;
            for(int i = 1; i < 9; i++)
            {
                emit newBullet(i);
            }
        }

//    }


    //move the player left
//    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
    else if(event->key() == Qt::Key_A)
    {
        trapDoor(-1,0);
        isAttacking = false;
        if(pos().x() <=70 && pos().x() > 20 && pos().y() >= 230 && pos().y() <= 250 && d[3] == 1) // left door
        {
            playery--;
            emit enterDoor();
            setPos(800,y());

            emit eatTaco(playerx,playery);
        }
        else if(pos().x() > 60)
        {
//            setPos(x()-10,y());
            isMovingLeft = true;
//            std::cout << pos().x() << " " << pos().y() << std::endl;
        }

    }
    //Move the player Right
//    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
    else if (event->key() == Qt::Key_D)
    {
        trapDoor(1,0);
        isAttacking = false;
        if(pos().x() >= 800 && pos().x() < 850 && pos().y() >= 230 && pos().y() <= 250 && d[1] == 1) // right door
        {
            playery++;
            emit enterDoor();
            setPos(60,y());

            emit eatTaco(playerx,playery);
        }
        else if(pos().x() + 100 < 895)
        {
//            setPos(x()+10,y());
            isMovingRight = true;
//            std::cout << pos().x() << " " << pos().y() << std::endl;
        }

    }
    //Move the player up
//    else if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
    else if (event->key() == Qt::Key_W)
    {
        trapDoor(0,-1);
        isAttacking = false;
        if(pos().x() >= 410 && pos().x() <= 440 && pos().y() <= 60 && pos().y() >= 30 && d[0] == 1) // top door
        {
            playerx--;
            emit enterDoor();
            setPos(x(),430);

            emit eatTaco(playerx,playery);
        }
        else if(pos().y() > 44)
        {
//            setPos(x(),y()-10);
            isMovingUp = true;
//            std::cout << pos().x() << " " << pos().y() << std::endl;
        }

    }
    //Move the player down
//    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
    else if (event->key() == Qt::Key_S)
    {
        trapDoor(0,1);
        isAttacking = false;
        if(pos().x() >= 410 && pos().x() <= 440 && pos().y() >= 430 && pos().y() < 460 && d[2] == 1) // bottom door
        {
            playerx++;
            emit enterDoor();
            setPos(x(),60);

            emit eatTaco(playerx,playery);
        }
        else if(pos().y() + 100 < 530)
        {
//            setPos(x(),y()+10);
            isMovingDown = true;
//            std::cout << pos().x() << " " << pos().y() << std::endl;
        }

    }


}

void Player::keyReleaseEvent(QKeyEvent *event)
{
//    pressedKeys.clear();
//   pressedKeys -= ((QKeyEvent*)event)->key();

    if (!event->isAutoRepeat()) {

        if (event->key() == Qt::Key_A)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isMovingLeft = false;
            QPixmap walking = csMajor->copy(0, 60, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if (event->key() == Qt::Key_D)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isMovingRight = false;
            QPixmap walking = csMajor->copy(0, 180, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if(event->key() == Qt::Key_W)
        {
            spriteAttackX = 0;
            spriteAttackY = 0;
            isMovingUp = false;
            QPixmap walking = csMajor->copy(0, 0, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if (event->key() == Qt::Key_S)
        {

            spriteAttackX = 0;
            spriteAttackY = 0;
            isMovingDown = false;
            QPixmap walking = csMajor->copy(0, 120, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();
        }
        pressedKeys.clear();
    }
}


void Player::timerEvent()
{
    if(isTrap)
    {
        isMovingLeft = false;
        isMovingRight = false;
        isMovingUp = false;
        isMovingDown = false;
        restartFrame();
        isTrap = false;

    }

    else if (!isAttacking)
    {
        if (isMovingLeft)
        {

            QPixmap walking = csMajor->copy(spriteCoordLeftRight, 60, 60, 60);
            this->setPixmap(walking);

            //left movement bounds
            if (pos().x() <= 50)
            {
                setPos(x(),y());
            }
            else
            {
              setPos(x()-velocity,y());
            }

            direct = 'a';
            nextFrame(direct);
        }
        else if (isMovingRight)
        {

            QPixmap walking = csMajor->copy(spriteCoordLeftRight, 180, 60, 60);
            this->setPixmap(walking);

            //right movement bounds
            if( pos().x() >= 810)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x()+velocity,y());
            }

            direct = 'd';
            nextFrame(direct);
        }
        else if (isMovingUp)
        {

            QPixmap walking = csMajor->copy(spriteCoordUpDown, 0, 60, 60);
            this->setPixmap(walking);

            //up movement bound
            if (pos().y() <= 44)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x(),y()-velocity);
            }

            direct = 'w';
            nextFrame(direct);
        }
        else if (isMovingDown)
        {

            QPixmap walking = csMajor->copy(spriteCoordUpDown, 120, 60, 60);
            this->setPixmap(walking);

            //down movement bound
            if(pos().y() >= 430)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x(),y()+velocity);
            }

            direct = 's';
            nextFrame(direct);
        }
    }

}


void Player::timerEvent2()
{
    if (isAttacking)
    {
        if(!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
        {
            QPixmap attacking = binaryStanding->copy(spriteAttackX, spriteAttackY, 60, 60);
            this->setPixmap(attacking);

            direct = 't';
            nextFrame(direct);
        }
        else if (isMovingLeft)
        {
            QPixmap attacking = binaryAttack->copy(spriteAttackX, spriteAttackY, 60, 60);
            this->setPixmap(attacking);

            //left movement bounds
            if (pos().x() <= 50)
            {
                setPos(x(),y());
            }
            else
            {
              setPos(x()-velocity,y());
            }

            direct = 'l';
            nextFrame(direct);
        }
        else if (isMovingRight)
        {
            QPixmap attacking = binaryAttack->copy(spriteAttackX, spriteAttackY, 60, 60);
            this->setPixmap(attacking);

            //right movement bounds
            if( pos().x() >= 810)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x()+velocity,y());
            }

            direct = 'r';
            nextFrame(direct);
        }
        else if (isMovingUp)
        {

            QPixmap attacking = binaryAttack->copy(spriteAttackX, spriteAttackY, 60, 60);
            this->setPixmap(attacking);

            //up movement bound
            if (pos().y() <= 44)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x(),y()-velocity);
            }

            direct = 'u';
            nextFrame(direct);
        }
        else if (isMovingDown)
        {

            QPixmap attacking = binaryAttack->copy(spriteAttackX, spriteAttackY, 60, 60);
            this->setPixmap(attacking);

            //down movement bound
            if(pos().y() >= 430)
            {
                setPos(x(),y());
            }
            else
            {
                setPos(x(),y()+velocity);
            }

            direct = 'b';
            nextFrame(direct);
        }
    }
}

void Player::nextFrame(char direction)
{
    switch (direction)
    {
        case 'a': {
            if (spriteCoordLeftRight == 480)
            {
              spriteCoordLeftRight = 0;

            }
            else
            {
              spriteCoordLeftRight += 60;

            }
            break;
        }
        case 'd': {
            if (spriteCoordLeftRight == 480)
            {
                spriteCoordLeftRight = 0;

            }
            else
            {
                spriteCoordLeftRight += 60;

            }
            break;
        }
        case 'w': {
            if (spriteCoordUpDown == 540)
            {
              spriteCoordUpDown = 0;
            }
            else
            {
              spriteCoordUpDown += 60;
            }
            break;
        }
        case 's': {
            if (spriteCoordUpDown == 540)
            {
              spriteCoordUpDown = 0;
            }
            else
            {
              spriteCoordUpDown += 60;
            }
            break;
        }
        case 'l': {
            if (spriteAttackY >= 180 && spriteAttackX >= 480)
            {
                isMovingLeft = false;
                isAttacking = false;
                spriteAttackX = 0;
                spriteAttackY = 120;
            }
            else if (spriteAttackY >= 120 && spriteAttackX >= 480)
            {
                spriteAttackY = 180;
                spriteAttackX = 0;
            }
            else
            {
                spriteAttackX += 60;
            }
            break;
        }
        case 'r': {
            if (spriteAttackY >= 420 && spriteAttackX >= 480)
            {
                isMovingRight = false;
                isAttacking = false;
                spriteAttackX = 0;
                spriteAttackY = 360;
            }
            else if (spriteAttackY >= 360 && spriteAttackX >= 480)
            {
                spriteAttackY = 420;
                spriteAttackX = 0;
            }
            else
            {
                spriteAttackX += 60;
            }
            break;
        }
        case 'u': {
            if (spriteAttackY >= 60 && spriteAttackX >= 540)
            {
                isMovingUp = false;
                isAttacking = false;
                spriteAttackX = 0;
                spriteAttackY = 0;
            }
            else if (spriteAttackY >= 0 && spriteAttackX >= 540)
            {
                spriteAttackY = 60;
                spriteAttackX = 0;
            }
            else
            {
                spriteAttackX += 60;
            }
            break;
        }
        case 'b': {
        qDebug() << spriteAttackX;
        qDebug() << spriteAttackY;
            if (spriteAttackY >= 300 && spriteAttackX >= 480)
            {
                isMovingDown = false;
                isAttacking = false;
                spriteAttackX = 0;
                spriteAttackY = 240;
            }
            else if (spriteAttackY >= 240 && spriteAttackX >= 480)
            {
                spriteAttackY = 300;
                spriteAttackX = 0;
            }
            else
            {
                spriteAttackX += 60;
            }
        }

        case 't': {

            if (spriteAttackY == 60 && spriteAttackX >= 720) {
                isAttacking = false;
                spriteAttackX = 0;
                spriteAttackY = 0;
            }
            else if (spriteAttackY == 0 && spriteAttackX >= 720)
            {
                spriteAttackY = 60;
                spriteAttackX = 0;
            }
            else
            {
                spriteAttackX += 60;
            }
            break;
        }

    }
}

void Player::restartFrame()
{
    spriteCoordLeftRight = 0;
    spriteCoordUpDown = 0;
}

void Player::trapDoor(int y,int x)
{
    if(temp->getFarX() == playerx+x && temp->getFarY() == playery+y)
    {
        isBoss2 = true;
    }
    else
    {
        isBoss2 = false;
    }
    //420,240
    if(temp->getFarX() == playerx && temp->getFarY() == playery)
    {
        if(pos().x()  <= 460 && pos().x() >=370 && pos().y() <=270 && pos().y() >=190)
        {
            qDebug() << "New Level";
            isTrap = true;
            emit newLevel();
        }
    }
}

void Player::setMap(Map *temp2)
{
    temp = temp2;
}
