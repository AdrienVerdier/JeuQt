#ifndef STATIC_ENTITY_H
#define STATIC_ENTITY_H

#include "entity.h"

class Static_Entity :public Entity
{
public:
    Static_Entity();
    void collision(Entity* entity, int position)  override;
    void update() override;
    ~Static_Entity();

private:

};

#endif // STATIC_ENTITY_H
