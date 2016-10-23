#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qlabel>
#include <QProgressBar>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
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
    int val = 0;                //test only. to be removed.
    int maxval = 100;           //test only. to be removed.
private slots:

    void on_pushButton_clicked(); //test only. to be removed.

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
