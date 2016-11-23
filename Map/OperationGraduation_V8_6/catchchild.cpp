#include "catchchild.h"


catchchild::catchchild(QWidget *parent) : QMdiSubWindow(parent)
{
    this->setFixedSize(1280,720);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->setStyleSheet("background: transparent;");
    this->setAttribute(Qt::WA_TranslucentBackground);

//    QLabel *lab = new QLabel;
//    lab->setGeometry(50,50,50,);

    QWidget *mccree = new QWidget(this);
    mccree->setGeometry(0,0,1280,720);
    this->setWidget(mccree);
//    this->installEventFilter(mou)
//    temp->show();
//    this->setWidget();
}

catchchild::~catchchild()
{

}

void catchchild::catcher(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
       emit catchfoc();

    }
}

