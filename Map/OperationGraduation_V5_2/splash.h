#ifndef SPLASH_H
#define SPLASH_H

#include <QSplashScreen>

class Splash : public QSplashScreen
{
public:
    Splash(QWidget *parent = 0);
    void update1();
    void update2();
};

#endif // SPLASH_H
