#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>

using namespace std;

//Base character class
class Character
{
    private:
        int cXpos;      //Character x position
        int cYpos;      //Character y position

        int cVel;      //Character velocity

        int cHealth;    //Character health
        int cHealthMx;  //Character max health
        int cDamage;    //Character damage
        int cArmor;     //Character Armor class
        int cCrit;      //Character crit chance

        string cName;   //Character name

    public:
        //Constructors & Deconstructor
        Character(); //Blank character
        Character(int, int, int, int); //(health, damage, armor, crit)
        Character(string, int, int, int, int); //(name, (see above))
        ~Character();

        //Max health set/get
        void setHpMx(int);
        int getHpMx(){return cHealthMx;}

        //Health set/get
        void setHp(int);
        int getHp(){return cHealth;}

        //Damage set/get
        void setDmg(int);
        int getDmg(){return cDamage;}

        //Armor set/get
        void setAC(int);
        int getAC(){return cArmor;}

        //Critical chance set/get
        void setCrit(int);
        int getCrit(){return cCrit;}

        //Sets coordinates
        void setCoor(int,int);

        //Velocity
        void setVel(int);
        int getVel(){return cVel;}

        //X-coor get/set
        void setX(int x){cXpos = x;}
        int getX(){return cXpos;}

        //Y-coor get/set
        void setY(int y){cYpos = y;}
        int getY(){return cYpos;}

        //Combat Functions
        int attack(); //Calculates attack
        int getHit(int); //Calculates health loss
        void attackChar(Character &target);//Calculates attack on target character
        void heal(int);//Restores char health
        bool isDead(){return cHealth < 1;}//returns death flag

        //Name set/get
        void setName(string name);
        string getName(){return cName;}

};

#endif // CHARACTER_H
