
#include <QApplication>
#include <iostream>
#include <ctime>
#include <item.h>
#include <inv.h>
#include <character.h>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    srand(time(0));

    //Item test
    cout <<"Item Test\n=========================\n";
    Item test;              //Create test item
    test.genStats(3);       //Generate stats
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d\n"
           "Crit: %d\n"
           "Speed: %d\n",
           test.getID(),
           test.getDmg(),
           test.getAC(),
           test.getCrit(),
           test.getVel());

    //Inv Test
    cout <<"\n\nInv Test\n=========================\n";
    Inv test2(5);           //Create test inv
    test2.genItems(3);      //Generate items
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d\n"
           "Crit: %d\n"
           "Speed: %d\n",
           test2.getItem(1).getID(),
           test2.getItem(1).getDmg(),
           test2.getItem(1).getAC(),
           test2.getItem(1).getCrit(),
           test2.getItem(1).getVel());

    //Character Test
    cout <<"\n\nCharacter Test\n=========================\n";
    Character test3("Bill", 100, 10, 10, 10);
    test3.createInv(5);
    test3.getInv()->genItems(3);

    cout <<"\nCharacter info\n=========================\n";
    cout <<"Name: " <<test3.getName() <<endl;
    printf("Hp: %d/%d\n"
           "Dmg: %d\n"
           "AC: %d\n"
           "Crit: %d\n",
           test3.getHp(),test3.getHpMx(),
           test3.getDmg(),
           test3.getAC(),
           test3.getCrit());

    cout <<"\n\nCharacter item 1\n=========================\n";
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d\n"
           "Crit: %d\n"
           "Speed: %d\n",
           test3.getInv()->getItem(1).getID(),
           test3.getInv()->getItem(1).getDmg(),
           test3.getInv()->getItem(1).getAC(),
           test3.getInv()->getItem(1).getCrit(),
           test3.getInv()->getItem(1).getVel());


    return 0;
    //return a.exec();
}
