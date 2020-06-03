#ifndef SMOKE_H
#define SMOKE_H


#include "alive_entity.h"

class smoke  : public Alive_Entity
{
public:
    smoke();
    void collision(Entity* entity, int position)  override;
    void update() override;

private:
    int cpt_frame;
};

#endif // SMOKE_H
