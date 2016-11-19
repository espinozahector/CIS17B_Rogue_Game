#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
private:
    int score;
public:
    Score(QGraphicsItem *parent =0);

    //Item increase and get
    void incScore();
    int getScore(){return score;}

};

#endif // SCORE_H
