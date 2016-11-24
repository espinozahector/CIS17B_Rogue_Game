#ifndef STATCHILD_H
#define STATCHILD_H

#include <QMdiSubWindow>
#include <QWidget>
#include <QMouseEvent>


namespace Ui {
    class StatChild;
}

class StatChild : public QMdiSubWindow
{
    Q_OBJECT

   public:
       explicit StatChild(QWidget *parent = 0);
       ~StatChild();
       void setName(std::string);       //set char name
       void updateDmg(int);        //update Attack
       void updateAC(int);         //update Armor
       void updateCrit(int);       //update Crit%
       void updateVel(int);        //update Speed
       void updateLvl(int);        //update Level
       void updateHealth(int);     //update current Health
       void updateMaxHealth(int);  //update max health
       void updateXpBar(int);      //update current XP bar
       void updateXpBarMax(int);   //update max XP bar
       void updateXp(int);         //update current XP text
       void updateXpMax(int);      //update max XP text
       void updateCharge(int);     //update 2nd attack charge
       int val;                //test only. to be removed.
       int maxval;           //test only. to be removed.

       void mousePressEvent(QMouseEvent *mouseEvent);
   private slots:

       void on_pushButton_clicked(); //test only. to be removed.

   private:
       Ui::StatChild *ui;

signals:
       statClick();

   };

#endif // STATCHILD_H
