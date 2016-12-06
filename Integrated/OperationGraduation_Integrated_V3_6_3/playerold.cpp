//User Libraries
#include "playerold.h"

#include <QDebug>
Player::Player(Map *base): QGraphicsPixmapItem()
{
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
    if (event->key() == Qt::Key_A)
    {
        isMovingLeft = false;
        QPixmap walking = csMajor->copy(0, 60, 60, 60);
        this->setPixmap(walking);
        restartFrame();


    } else if (event->key() == Qt::Key_D)
    {
        isMovingRight = false;
        QPixmap walking = csMajor->copy(0, 180, 60, 60);
        this->setPixmap(walking);
        restartFrame();


    } else if(event->key() == Qt::Key_W)
    {
        isMovingUp = false;
        QPixmap walking = csMajor->copy(0, 0, 60, 60);
        this->setPixmap(walking);
        restartFrame();


    } else if (event->key() == Qt::Key_S)
    {
        isMovingDown = false;
        QPixmap walking = csMajor->copy(0, 120, 60, 60);
        this->setPixmap(walking);
        restartFrame();

    }
}

void Player::timerEvent()
{
    char direct;

    if (isMovingLeft)
    {
        direct = 'l';
        QPixmap walking = csMajor->copy(spriteCoordLeftRight, 60, 60, 60);
        this->setPixmap(walking);
        setPos(x()-velocity,y());
        nextFrame(direct);
    }
    else if (isMovingRight)
    {
        direct = 'r';
        QPixmap walking = csMajor->copy(spriteCoordLeftRight, 180, 60, 60);
        this->setPixmap(walking);
        setPos(x()+velocity,y());
        nextFrame(direct);
    }
    else if (isMovingUp)
    {
        direct = 'u';
        QPixmap walking = csMajor->copy(spriteCoordUpDown, 0, 60, 60);
        this->setPixmap(walking);
        setPos(x(),y()-velocity);
        nextFrame(direct);
    }
    else if (isMovingDown)
    {
        direct = 'd';
        QPixmap walking = csMajor->copy(spriteCoordUpDown, 120, 60, 60);
        this->setPixmap(walking);
        setPos(x(),y()+velocity);
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
