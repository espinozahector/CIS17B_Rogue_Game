#include "statchild.h"
#include "ui_statchild.h"

StatChild::StatChild(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::StatChild)
{
    ui->setupUi(this);
    //ui->bgGraphic->setPixmap(QPixmap("StatusBG.jpg"));

    //set style for health, xp and special bars
    ui->healthBar->setStyleSheet("#healthBar {border: 3px solid rgb(83, 75, 50);"
                                 " border-radius:10px; background-color: rgb(114, 97, 75);"
                                 " padding:0px;} #healthBar::chunk {background-color: red;"
                                 " border-radius:10px;}");
    ui->xpBar->setStyleSheet("#xpBar {border: 3px solid rgb(88, 75, 50); border-radius:10px;"
                             " background-color: rgb(114, 97, 75); padding:0px;} "
                             "#xpBar::chunk {background-color: rgb(170, 170, 170);"
                             " border-radius:10px;}");
    ui->specialBar->setStyleSheet("#specialBar {border: 3px solid rgb(80, 75, 50);"
                                  " border-radius:10px; background-color: rgb(114, 97, 75);"
                                  " padding:0px;} #specialBar::chunk {background-color:"
                                  " rgb(85, 255, 255); border-radius:10px;}");
    //set value examples. to be removed.
    updateHealth(0);
    updateXp(0);
    updateXpBar(0);
    updateCharge(0);
    updateCrit(0);
    updateDmg(7);
    updateAC(11);
    updateVel(57);
}

StatChild::~StatChild()
{
    delete ui;
}

void StatChild::setName(std::string name)
{
    ui->charName->setText(QString::fromStdString(name));
}
void StatChild::updateDmg(int amount)
{
    if (amount < 10)
    {
        ui->attackNumber->setText("0" + QString::number(amount));
    }
    else
    {
        ui->attackNumber->setText(QString::number(amount));
    }
}

void StatChild::updateAC(int amount)
{
    if (amount < 10)
    {
        ui->armorNumber->setText("0" + QString::number(amount));
    }
    else
    {
        ui->armorNumber->setText(QString::number(amount));
    }
}

void StatChild::updateCrit(int amount)
{
    if (amount < 10)
    {
        ui->critNumber->setText("0" + QString::number(amount));
    }
    else
    {
        ui->critNumber->setText(QString::number(amount));
    }
}

void StatChild::updateVel(int amount)
{
    if (amount < 10)
    {
        ui->speedNumber->setText("0" + QString::number(amount));
    }
    else
    {
        ui->speedNumber->setText(QString::number(amount));
    }
}

void StatChild::updateLvl(int amount)
{
    if (amount < 10)
    {
        ui->levelNumber->setText("0" + QString::number(amount));
    }
    else
    {
        ui->levelNumber->setText(QString::number(amount));
    }
}

void StatChild::updateHealth(int amount)
{
    ui->healthBar->setValue(amount);
}

void StatChild::updateMaxHealth(int amount)
{
    ui->healthBar->setMaximum(amount);
}

void StatChild::updateXpBar(int amount)
{
    ui->xpBar->setValue(amount);
}

void StatChild::updateXpBarMax(int amount)
{
    ui->xpBar->setMaximum(amount);
}

void StatChild::updateXp(int amount)
{
    ui->xpCurrentNumber->setText(QString::number(amount));
}

void StatChild::updateXpMax(int amount)
{
    ui->xpNextLvlNumber->setText("/" + QString::number(amount));
}

void StatChild::updateCharge(int amount)
{
    ui->specialBar->setValue(amount);
}
//for test only. to be removed.
void StatChild::on_pushButton_clicked()
{
    val+=2;
    updateHealth(val);      //change to any function to test
}
