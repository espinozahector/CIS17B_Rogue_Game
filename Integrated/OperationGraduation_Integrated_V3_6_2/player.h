#ifndef PLAYER_H
#define PLAYER_H

//System and Qt Libraries
//SOME OF THESE MAY HAVE CARRIED OVER
//FROM CHARACTER TEAM, AND MAY BE
//UNNECESSARY
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>
#include <QMediaPlayer>
using namespace std;

#include "map.h"
#include "character.h"

/*Player class
 * This class acts as the primary controller from the player
 *

*/
class Player : public QObject, public QGraphicsPixmapItem, public Character
{
    Q_OBJECT

    private:
        int pLvl;           //Player level
        int pExp;           //Player current exp
        int pExpMx;         //Player max exp

        int pCharge;       //Player charge val for special attack

        int playerx;    // used for player location on the map ! the room
        int playery;    // used for player location on the map ! the room
        int lvlCnt;     // Counts the levels completed

    public:
        //Constructors
        Player(Map *);
        //Param(name,health,damage,armor,crit)
        //Player(string, int, int, int, int);

        Map *temp;
        bool isBoss2;
        bool isTrap;

        //to process multiple key pressed
        QSet<int> pressedKeys;

        //returns true if player is moving
        bool isMovingLeft;
        bool isMovingRight;
        bool isMovingUp;
        bool isMovingDown;

        char direct; //hold direction

        //returns true if player is attacking
        bool isAttacking;

        //holds speed
        int velocity;

        QTimer *timer;
        QTimer *timer2;

        QPixmap *csMajor;
        QPixmap *binaryAttack;
        QPixmap *binaryStanding;

        //holds values to move to the next frame
        int spriteCoordLeftRight;
        int spriteCoordUpDown;
        int spriteAttackX;
        int spriteAttackY;

        //Level functions
        //Sets level(value)
        //Level must be 0-99
        void setLvl(int);           //Sets lvl
        int getLvl(){return pLvl;}  //Gets lvl

        //Calc player stat increase
        //Ex) See Char_v5 enemy.scaleUp()
        //Resets exp to currentExp - maxExp for exp carry
        bool levelup(int);

        //Experience
        //Sets exp(value)
        //Allow values 0-9999
        //returns true if the exp exceeds maxExp
        bool setExp(int);
        //Adds exp(value)
        //Returns true if exp exceeds maxExp
        bool addExp(int);
        int getExp(){return pExp;}       //Returns exp

        //Max Experience
        void setExpMx(int);     //Sets max exp(0-9999)
        int getExpMx(){return pExpMx;}     //Returns max exp

        //Charge
        int getCharge(){return pCharge;}//Returns special charge
        //Increases special charge by a set amount of 5
        //Special charge cannot exceed max charge(100)
        void incCharge();
        //Returns true once the charge reaches a set amount of 100
        bool isCharged();   //Returns charge flag
        //Calc/returns special attack
        //Does not run if isCharged() returns false
        //Resets charge to 0 if ran
        int special();

        //Equipped/Dequip functions
        //void equip(int);
        //void dequip(int);
        void refreshStatCh();

    void nextFrame(char direction);
        void restartFrame();

        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent * event);

        int getMapX() {return playerx;}
        int getMapY() {return playery;}
        void setMapX(int x) {playerx = x;}
        void setMapY(int y) {playery = y;}
        void setLvlCnt(int val) {lvlCnt = val;}
        int getLvlCnt() {return lvlCnt;}
        void trapDoor(int,int);
        void setMap(Map*);

    signals:
        void playToStat(int, int, int, int, int, int, int);  //constant stat update for StatChild
        void playLvlUpdate(std::string, int, int, int);      //stat update for StatChild when levelling
        void enterDoor();       // New Room
        void eatTaco(int,int);  // MiniMap
        void newLevel();        // New Level
        void newBullet(int);       //Binary Projectile
    public slots:
        void timerEvent(); //handles player movement
        void timerEvent2();
};

#endif // PLAYER_H
