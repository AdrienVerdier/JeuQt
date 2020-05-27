#ifndef PEACH_H
#define PEACH_H

#include "alive_entity.h"

class Peach : public Alive_Entity
{
public:
    Peach();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // PEACH_H
