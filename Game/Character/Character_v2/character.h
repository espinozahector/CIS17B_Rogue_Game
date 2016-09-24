#ifndef CHARACTER_H
#define CHARACTER_H


//Base character class
class Character
{
    private:
        int cHealth; //Character health
        int cDamage; //Character damage
        int cArmor; //Character Armor class
        int cCrit; //Character crit chance
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
        void setCrit(int);
        int getCrit(){return cCrit;}

        //Action functions
        int attack();
        void calcDmg(int);
};

#endif // CHARACTER_H
