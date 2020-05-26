#ifndef MARIO_H
#define MARIO_H

#include "alive_entity.h"
#include "../Tools/controls.h"
#include "Models/block.h"
#include "Models/goomba.h"

class Mario : public Alive_Entity
{
public:
    Mario();
    void collision(Entity* entity, int position);
    void collision(Block* entity, int position);
    void collision(Goomba* entity, int position);

private:
    Controls *input;

};

#endif // MARIO_H
