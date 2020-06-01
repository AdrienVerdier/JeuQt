#ifndef PLANTE_H
#define PLANTE_H


#include "alive_entity.h"

class plante : public Alive_Entity
{
public:
    plante();
    void collision(Entity* entity, int position)  override;
    void update() override;
};


#endif // PLANTE_H
