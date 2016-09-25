
#include <character.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //Character (health, damage, armor, crit chance)
    Character slime("Slime",100,100,10,10);
    Character warrior("Warrior", 200,100,10,10);

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
