#ifndef GOOMBA_H
#define GOOMBA_H

#include "alive_entity.h"

class Mario;
class Goomba : public Alive_Entity
{
public:
    Goomba();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // GOOMBA_H
