#ifndef BLOCKGRASS_H
#define BLOCKGRASS_H

#include "static_entity.h"

class BlockGrass  : public Static_Entity
{
public:
    BlockGrass();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // BLOCKGRASS_H
