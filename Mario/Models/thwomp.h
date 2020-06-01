#ifndef THWOMP_H
#define THWOMP_H

#include "alive_entity.h"

class thwomp : public Alive_Entity
{
public:
    thwomp();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // THWOMP_H
