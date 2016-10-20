#include <QApplication>
#include <iostream>
#include <ctime>

#include "item.h"
#include "inv.h"
#include "character.h"
#include "pcsmaj.h"
#include "edebt.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    srand(time(0));

    //Item test
    cout <<"Item Test\n=========================\n";
    Item test;              //Create test item
    test.genStats(3);       //Generate stats
    cout <<"Name: " <<test.getName() <<endl;
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
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
    test2.genInv(3);      //Generate items
    cout <<"Name: " <<test2.getItem(1).getName() <<endl;
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
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
    test3.getInv()->genInv(3);

    cout <<"\nCharacter info\n=========================\n";
    cout <<"Name: " <<test3.getName() <<endl;
    printf("Hp: %d/%d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
           "Crit: %d\n",
           test3.getHp(),test3.getHpMx(),
           test3.getDmg(),
           test3.getAC(),
           test3.getCrit());

    cout <<"\n\nCharacter item 1\n=========================\n";
    cout <<"Name: " <<test3.getInv()->getItem(1).getName() <<endl;
    printf("ID: %d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
           "Crit: %d\n"
           "Speed: %d\n",
           test3.getInv()->getItem(1).getID(),
           test3.getInv()->getItem(1).getDmg(),
           test3.getInv()->getItem(1).getAC(),
           test3.getInv()->getItem(1).getCrit(),
           test3.getInv()->getItem(1).getVel());

    //Player Test
    cout <<"\n\nPlayer Test\n=========================\n";
    pCsMaj player("Joe");
    cout <<"Class: " <<player.getClass() <<endl
        <<"Name: " <<player.getName() <<endl;
    printf("Hp: %d/%d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
           "Crit: %d\n"
           "Exp: %d/%d\n",
           player.getHp(),player.getHpMx(),
           player.getDmg(),
           player.getAC(),
           player.getCrit(),
           player.getExp(),player.getExpMx());


    //Enemy Test
    cout <<"\n\nEnemy Test\n=========================\n";
    eDebt enemy(player.getLvl());
    cout <<"Enemy: " <<enemy.getName() <<endl;
    printf("Hp: %d/%d\n"
           "Dmg: %d\n"
           "AC: %d%%\n"
           "Crit: %d\n",
           enemy.getHp(),enemy.getHpMx(),
           enemy.getDmg(),
           enemy.getAC(),
           enemy.getCrit());


    //Combat Test
    cout <<"\n\nCombat Test\n=========================\n";

    //Player attacks
    cout <<player.getName() <<" attacks dealing "
        <<player.attack1(enemy) <<" to the "
        <<enemy.getName() <<endl;

    //Enemy attacks
    cout <<enemy.getName() <<" attacks dealing "
        <<enemy.attack1(player) <<" to "
        <<player.getName() <<endl;

    //Player kills enemy
    cout <<player.getName() <<" rages and murders the "
        <<enemy.getName() <<" earning 100 experience!\n\n";

    enemy.setHp(0);

    if(enemy.isDead()){
        if(player.levelup(105)){
           cout <<"Player leveled up!\n==================\n";
           cout <<"Class: " <<player.getClass() <<endl
               <<"Name: " <<player.getName() <<endl;
           printf("Hp: %d/%d\n"
                  "Dmg: %d\n"
                  "AC: %d%%\n"
                  "Crit: %d\n"
                  "Exp: %d/%d\n",
                  player.getHp(),player.getHpMx(),
                  player.getDmg(),
                  player.getAC(),
                  player.getCrit(),
                  player.getExp(), player.getExpMx());

        }

        //Item grab test
        cout <<"\n\nItem Grab Test\n=========================\n";
        cout <<"Enemy dropped an item!\n";

        Item newitem = enemy.drop();

        player.grabItem(newitem);
        cout <<"Name: "
            <<player.getInv()->getItem(newitem.getID()).getName();
        printf("\nID: %d\n"
               "Dmg: %d\n"
               "AC: %d%%\n"
               "Crit: %d\n"
               "Speed: %d\n",
               newitem.getID(),
               newitem.getDmg(),
               newitem.getAC(),
               newitem.getCrit(),
               newitem.getVel());

        cout <<"\n\nNew Player Stats\n===========================\n";
        printf("Hp: %d/%d\n"
               "Dmg: %d\n"
               "AC: %d%%\n"
               "Crit: %d\n"
               "Speed: %d\n",
               player.getHp(),player.getHpMx(),
               player.getDmg(),
               player.getAC(),
               player.getCrit(),
               player.getVel());

    }

    return 0;
    //return a.exec();
}
