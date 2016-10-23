#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bgGraphic->setPixmap(QPixmap("StatusBG.jpg"));

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(std::string name)
{
    ui->charName->setText(QString::fromStdString(name));
}
void MainWindow::updateDmg(int amount)
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

void MainWindow::updateAC(int amount)
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

void MainWindow::updateCrit(int amount)
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

void MainWindow::updateVel(int amount)
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

void MainWindow::updateLvl(int amount)
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

void MainWindow::updateHealth(int amount)
{
    ui->healthBar->setValue(amount);
}

void MainWindow::updateMaxHealth(int amount)
{
    ui->healthBar->setMaximum(amount);
}

void MainWindow::updateXpBar(int amount)
{
    ui->xpBar->setValue(amount);
}

void MainWindow::updateXpBarMax(int amount)
{
    ui->xpBar->setMaximum(amount);
}

void MainWindow::updateXp(int amount)
{
    ui->xpCurrentNumber->setText(QString::number(amount));
}

void MainWindow::updateXpMax(int amount)
{
    ui->xpNextLvlNumber->setText("/" + QString::number(amount));
}

void MainWindow::updateCharge(int amount)
{
    ui->specialBar->setValue(amount);
}
//for test only. to be removed.
void MainWindow::on_pushButton_clicked()
{
    val+=2;
    updateHealth(val);      //change to any function to test
}
