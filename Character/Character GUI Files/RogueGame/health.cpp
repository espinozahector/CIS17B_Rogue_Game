#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    //Set hp
    hp = 100;

    //Draw text
    setPlainText(QString("Health: " + QString::number(hp)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Health::decHp(){
    //Decrease health
    hp -=5;
    //Redraw text
    setPlainText(QString("Health: " + QString::number(hp)));
}
