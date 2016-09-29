#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>

using namespace std;

//Base character class
class Character
{
    private:
        int cHealth; //Character health
        int cDamage; //Character damage
        int cArmor; //Character Armor class
        int cCrit; //Character crit chance
        string cName; //Character name

    public:
        //Constructors & Deconstructor
        Character();
        Character(int, int, int, int);
        Character(string, int, int, int, int);
        ~Character();

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

        //Combat Functions
        int attack(); //Calculates attack
        int getHit(int); //Calculates health loss
        void attackChar(Character &target);//Calculates attack on target character
        bool isDead(){return cHealth < 1;}//returns death flag

        //Name set/get
        void setName(string name);
        string getName(){return cName;}

};

#endif // CHARACTER_H
