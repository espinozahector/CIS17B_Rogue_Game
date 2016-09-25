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
        int cArmor; //Character Armor
        float cCrit; //Character crit chance
        string cName; //Character Name

    public:
        //Constructors & Deconstructor
        Character();
        Character(int, int, int, float);
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
        void setCrit(float);
        float getCrit(){return cCrit;}

        //Action functions
        int attack();
        void calcDmg(int);

        //have two instances attack
        void attackChar(Character &target);

        //Name set/get
        void setName(string name);
        string getName(){return cName;}
};

#endif // CHARACTER_H
