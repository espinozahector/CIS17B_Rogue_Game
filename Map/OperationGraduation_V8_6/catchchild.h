#ifndef CATCHCHILD_H
#define CATCHCHILD_H

#include <QMdiSubWindow>
#include <QEvent>
#include <QLabel>

class catchchild : public QMdiSubWindow
{
    Q_OBJECT
public:
    catchchild(QWidget *parent = 0);
    ~catchchild();
    void catcher(QEvent *);
signals:
    void catchfoc();
};

#endif // CATCHCHILD_H
