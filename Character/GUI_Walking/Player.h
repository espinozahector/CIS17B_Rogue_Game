#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPropertyAnimation>
#include <QWidget>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    // true: player is moving; false: player is not moving
    bool pMovement;

    //remembers the leading foot
    bool footLeft;
    bool footRight;

public slots:

    //character right movement
    void moveRight();   //signals the other moveRight# functions
    void moveRight1();  //character looking right
    void moveRight2();  //character moving right_1
    void moveRight3();  //character moving right_2

    //character left movement
    void moveLeft();    //signals the other moveLeft# functions
    void moveLeft1();   //character looking left
    void moveLeft2();   //character moving left_1
    void moveLeft3();   //character moving left_2

    //character up movement
    void moveUp();    //signals the other moveUp# functions
    void moveUp1();   //character looking back
    void moveUp2();   //character moving back_1
    void moveUp3();   //character moving back_2


    //character down movement
    void moveDown();    //signals the other moveDown# functions
    void moveDown1();   //character looking front
    void moveDown2();   //character moving front_1
    void moveDown3();   //character moving font_2

    //set's direction character is moving
    void movement();    //sets player movement true
    void idle();        //sets player movement false


};

#endif // PLAYER_H
