#ifndef SMOKE_H
#define SMOKE_H


#include "static_entity.h"

class smoke  : public Static_Entity
{
public:
    smoke();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // SMOKE_H
