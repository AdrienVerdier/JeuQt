#ifndef FLAMME_H
#define FLAMME_H


#include "alive_entity.h"

class flamme : public Alive_Entity
{
public:
    flamme();
    void collision(Entity* entity, int position)  override;
    void update() override;
};
#endif // FLAMME_H
