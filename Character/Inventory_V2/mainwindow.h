#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "item.h"
#include <QMainWindow>

namespace Ui
{
class Inventory;
}

class Inventory : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = 0);
    Item equip[6];

    ~Inventory();

private slots:
    void on_helmet_linkHovered(const QString &link);
    void on_chest_linkHovered(const QString &link);
    void on_legs_linkHovered(const QString &link);
    void on_shoes_linkHovered(const QString &link);
    void on_weapon_1_linkHovered(const QString &link);
    void on_weapon_2_linkHovered(const QString &link);

private:
    Ui::Inventory *ui;
};

#endif // MAINWINDOW_H
