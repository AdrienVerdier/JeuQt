#ifndef SPIKE_H
#define SPIKE_H

#include "static_entity.h"

class spike  : public Static_Entity
{
public:
    spike();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // SPIKE_H
