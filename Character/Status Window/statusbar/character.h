#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
//#include <inv.h>

using namespace std;

//Base character class
class Character
{
    private:
        string cName;   //Character name

        int cHealth;    //Character health
        int cHealthMx;  //Character max health
        int cDamage;    //Character damage
        int cArmor;     //Character Armor class
        int cCrit;      //Character crit chance
        int cVel;       //Character movement speed

//        Inv *cInv;      //Character inventory

    public:
        //Constructors & Deconstructor
        Character(); //Blank character
        //Param(Name, hp, dmg, armor, crit)
        Character(string, int, int, int, int);
        ~Character();

        //Name set/get
        void setName(string name);
        string getName(){return cName;}

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

        //Velocity
        void setVel(int);
        int getVel(){return cVel;}

        //Create inventory (capacity)
        void createInv(int);
//        Inv *getInv(){return cInv;}

        //Combat Functions
        int attack();   //Calculates damage
        int attack1(Character&); //Calc & returns primary on target character
        int attack2(Character&); //Calc & returns secondary attack on character
        int getHit(int);        //Calc & return health loss
        bool isDead(){return cHealth < 1;} //Returns death flag
        int heal(int);  //Calc/return player heal
};


#endif // CHARACTER_H
