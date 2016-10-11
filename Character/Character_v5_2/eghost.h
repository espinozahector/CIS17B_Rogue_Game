#ifndef EGHOST_H
#define EGHOST_H

#include "enemy.h"

class EGhost : public Enemy
{
public:
    EGhost();

    int skill_1();
    int skill_2();

    void render();
};

#endif // EGHOST_H
