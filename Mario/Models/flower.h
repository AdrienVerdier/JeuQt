#ifndef FLOWER_H
#define FLOWER_H


#include "alive_entity.h"

class Mario;
class flower : public Alive_Entity
{
public:
    flower();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // FLOWER_H
