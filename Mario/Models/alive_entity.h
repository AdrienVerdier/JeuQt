#ifndef ALIVE_ENTITY_H
#define ALIVE_ENTITY_H

#include "entity.h"

class Alive_Entity : public Entity
{
public:
    Alive_Entity();
    void collision(Entity* entity, int position)  override;
    void update() override;

protected:
    bool move_to_left;
    bool move_to_right;
    bool move_to_down;
    bool move_to_up;

};

#endif // ALIVE_ENTITY_H
