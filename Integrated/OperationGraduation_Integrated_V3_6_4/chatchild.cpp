#include "chatchild.h"
#include "ui_chatchild.h"

ChatChild::ChatChild(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::ChatChild)
{
    ui->setupUi(this);

    chat = new QPlainTextEdit(this);
    chat->setGeometry(0,0,350,500);

    message = new QLineEdit(this);
    message->setGeometry(0,550,350,50);
}

ChatChild::~ChatChild()
{
    delete ui;
    delete chat;
    delete message;
}
