#ifndef MUSHROOM_H
#define MUSHROOM_H


#include "alive_entity.h"

class Mario;
class mushroom : public Alive_Entity
{
public:
    mushroom();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // MUSHROOM_H
