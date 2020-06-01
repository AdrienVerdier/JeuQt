#ifndef KOOPA_H
#define KOOPA_H


#include "alive_entity.h"

class Mario;
class Koopa : public Alive_Entity
{
public:
    Koopa();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // KOOPA_H
