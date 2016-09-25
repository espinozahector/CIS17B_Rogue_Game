
#include <character.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //Character (health, damage, armor, crit chance)
    Character slime(100,100,10,10);
    Character warrior(200,100,10,10);

    //setName
    slime.setName("Slime");
    warrior.setName("Warrior");

    cout << "\nBefore Attack" << endl
         << warrior.getName() << " Health:  " << warrior.getHp() << endl
         << slime.getName() <<  " Health:  " << slime.getHp() << endl << endl;

    warrior.attackChar(slime);
    slime.attackChar(warrior);

    //Note: armor effects damage!
    cout << "\nAfter Attack" << endl
         << warrior.getName() << " Health:  " << warrior.getHp() << endl
         << slime.getName() <<  " Health:  " << slime.getHp() << endl << endl;

    return 0;
}
