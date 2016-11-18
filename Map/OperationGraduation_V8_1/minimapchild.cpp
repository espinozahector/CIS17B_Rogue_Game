#include "minimapchild.h"

#include <QStyle>
MiniMapChild::MiniMapChild(QWidget *parent) :
    QMdiSubWindow(parent)
{
    this->setFixedSize(350,150);

    tacobell = new QLabel[81];
    this->setWidget(tacobell);

    tacobell->setStyleSheet("background-color:FFF");

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            tacobell[(i*j)+j].setStyleSheet("background-color:#333;");
            tacobell[(i*j)+j].setGeometry(i*35,j*15,35,15); //Moves and sets the size
            tacobell[(i*j)+j].setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
//            tacobell[(i*j)+j].setVisible(false);
        }
    }

//    for(int i = 0; i<9; i++){
//        for(int j = 0; j<9; j++){
//            tacobell[(i*j)+j].setStyleSheet("background-color: #115285;");
//        }
//    }
    tacobell[40].setStyleSheet("background-color: #115285;");
//    tacobell->style()->unpolish(tacobell);
//    tacobell->style()->polish(tacobell);
//    tacobell->update();
}
MiniMapChild::~MiniMapChild()
{

}

void MiniMapChild::update(int x, int y)
{
    tacobell[40].setStyleSheet("background-color: #115285;");
}

void MiniMapChild::clearTacos()
{
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            tacobell[(i*j)+j].setVisible(false);
        }
    }
    tacobell[(4*4)+4].setVisible(true);
}
