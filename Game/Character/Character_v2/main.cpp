
#include <character.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Character slime(100,100,10,10);

    cout <<"Slime attacks and deals " <<slime.attack() <<" damage.\n";

    return 0;
}
