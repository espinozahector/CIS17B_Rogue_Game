#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"

Inventory::Inventory(QWidget *parent): QMainWindow(parent),
    ui(new Ui::Inventory)
{
    ui->setupUi(this);
}

Inventory::~Inventory()
{
    delete ui;
}

void Inventory::on_helmet_linkHovered(const QString &link)
{
    equip[0].display();
}

void Inventory::on_chest_linkHovered(const QString &link)
{
    equip[1].display();
}

void Inventory::on_legs_linkHovered(const QString &link)
{
    equip[2].display();
}

void Inventory::on_shoes_linkHovered(const QString &link)
{
    equip[3].display();
}

void Inventory::on_weapon_1_linkHovered(const QString &link)
{
    equip[4].display();
}

void Inventory::on_weapon_2_linkHovered(const QString &link)
{
    equip[5].display();
}
