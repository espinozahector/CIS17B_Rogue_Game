#include "splash.h"

Splash::Splash(QWidget *parent) : QSplashScreen(parent)
{
    this->setPixmap(QPixmap(":/Other/images/other/Title.png"));
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
