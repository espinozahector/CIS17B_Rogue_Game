#include "chatchild.h"
#include "ui_chatchild.h"

ChatChild::ChatChild(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::ChatChild)
{
    ui->setupUi(this);


}

ChatChild::~ChatChild()
{
    delete ui;
}
