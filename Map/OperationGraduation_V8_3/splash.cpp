#include "splash.h"

Splash::Splash(QWidget *parent) : QSplashScreen(parent)
{
    version = "<h3>Alpha Version 7.5</h3>";
    this->setPixmap(QPixmap(":/Other/images/other/Title.png"));
    this->setFocus();
    this->show();
}

void Splash::update1()
{
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    this->showMessage(QObject::tr("<h3>Setting up the main window...</h3>"),
                      topRight, Qt::white);
}

void Splash::update2()
{
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    this->showMessage(QObject::tr("<h3>Loading the main window...</h3>"),
                      topRight, Qt::white);
}

void Splash::showVersion()
{
    this->version = version;
    this->showMessage(this->version,Qt::AlignLeft,Qt::black);
}
