#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    //Initialize the score to 0
    score = 0;

    //Draw text (converts number to string)
    setPlainText(QString("Score: ") + QString::number(score));
    //Sets text color
    setDefaultTextColor(Qt::blue);
    //Creates new font("fontname", size)
    setFont(QFont("times",16));
}

void Score::incScore(){
    //Increment score
    score++;

    //Redraw text
    setPlainText(QString("Score: ") + QString::number(score));

}
