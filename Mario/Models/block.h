#ifndef BLOCK_H
#define BLOCK_H

#include "static_entity.h"

class Block  : public Static_Entity
{
public:
    Block();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // BLOCK_H
