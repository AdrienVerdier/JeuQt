#ifndef GROUND_H
#define GROUND_H

#include "static_entity.h"


class Ground : public Static_Entity
{
public:
    Ground();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // GROUND_H
