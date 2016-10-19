#ifndef SPLASH_H
#define SPLASH_H

#include <QSplashScreen>
#include <QLabel>

class Splash : public QSplashScreen
{
public:
    Splash(QWidget *parent = 0);
    void update1(); //loading updates
    void update2();
    void version(); //posting version number
};

#endif // SPLASH_H
