#ifndef SPLASH_H
#define SPLASH_H

#include <QSplashScreen>
#include <QPainter>

class Splash : public QSplashScreen
{
private:
    QString version;
public:
    Splash(QWidget *parent = 0);
    void update1(); //loading updates
    void update2();
    void showVersion(); //posting version number
};

#endif // SPLASH_H
