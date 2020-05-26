#ifndef MARIO_H
#define MARIO_H

#include "alive_entity.h"
#include "../Tools/controls.h"

class Mario : public Alive_Entity
{
public:
    Mario();

private:
    Controls *input;
};

#endif // MARIO_H
