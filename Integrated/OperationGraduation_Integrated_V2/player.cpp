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

    velocity = 10;

    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;

    spriteCoordLeftRight = 0;
    spriteCoordUpDown = 0;

    csMajor = new QPixmap(":/Character/images/characters/cs_walking.png");

    QPixmap walking = csMajor->copy(0, 120, 60, 60);

    setPixmap(walking);

    this->timer = new QTimer;

    timer->setInterval(20);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
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


    //move the player left
//    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
    if(event->key() == Qt::Key_A)
    {
        trapDoor(-1,0);
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

    if (!event->isAutoRepeat()) {

        if (event->key() == Qt::Key_A)
        {
            isMovingLeft = false;
            QPixmap walking = csMajor->copy(0, 60, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if (event->key() == Qt::Key_D)
        {
            isMovingRight = false;
            QPixmap walking = csMajor->copy(0, 180, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if(event->key() == Qt::Key_W)
        {
            isMovingUp = false;
            QPixmap walking = csMajor->copy(0, 0, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();


        } else if (event->key() == Qt::Key_S)
        {
            isMovingDown = false;
            QPixmap walking = csMajor->copy(0, 120, 60, 60);
            this->setPixmap(walking);
            refreshStatCh();    //TEST TO BE REMOVED
            levelup(1);         //TEST TO BE REMOVED
            restartFrame();

        }
    }
}

void Player::timerEvent()
{
    char direct;

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

        direct = 'l';
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

        direct = 'r';
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

        direct = 'u';
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

        direct = 'd';
        nextFrame(direct);
    }

}

void Player::nextFrame(char direction)
{
    switch (direction)
    {
        case 'l': {
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
        case 'r': {
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
        case 'u': {
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
        case 'd': {
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
            emit newLevel();
        }
    }
}

void Player::setMap(Map *temp2)
{
    temp = temp2;
}


//REFERENCE FOR THE SMOOTH MOVEMENT

//void Player::keyPressEvent(QKeyEvent *event)
//{
//    const int FPS = 60;

//    // move player left
//    if (event->key() == Qt::Key_A) {
//        if (direction == directions::right) {
//            // face character left
//            setTransform(QTransform::fromScale(-1, 1));
//            direction = directions::left;
//        }

//        if (!moveTimer->isActive()) {
//            moveTimer->start(1000/FPS);
//        }
//    }
//    // move player right
//    else if (event->key() == Qt::Key_D) {
//        if (direction == directions::left) {
//            // face character right
//            setTransform(QTransform::fromScale(1, 1));
//            direction = directions::right;
//        }

//        if (!moveTimer->isActive()) {
//            moveTimer->start(1000/FPS);
//        }
//    }
//}

//void Player::keyReleaseEvent(QKeyEvent *event)
//{
//    // stop player moving left or right
//    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D) {

//        if (moveTimer->isActive()) {
//            moveTimer->stop();
//        }
//    }
//}

//void Character::move()
//{
//    const double DISTANCE_MOVED_PER_FRAME = 1.0;

//    if (direction == directions::right) {
//        // player wants to move right
//        setPos(x() + DISTANCE_MOVED_PER_FRAME,y());
//    }
//    else {
//        // player wants to move left
//        setPos(x() - DISTANCE_MOVED_PER_FRAME,y());
//    }
//}
