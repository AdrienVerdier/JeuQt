#ifndef GOOMBA_H
#define GOOMBA_H

#include "alive_entity.h"

class Goomba : public Alive_Entity
{
public:
    Goomba();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // GOOMBA_H
