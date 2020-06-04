#ifndef BOWSER_FIRE_H
#define BOWSER_FIRE_H

#include "alive_entity.h"

class Mario;
class bowser_fire : public Alive_Entity
{
public:
    bowser_fire();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // BOWSER_FIRE_H
