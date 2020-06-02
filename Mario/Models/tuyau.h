#ifndef TUYAU_H
#define TUYAU_H

#include "static_entity.h"

class Tuyau : public Static_Entity
{
public:
    Tuyau();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // TUYAU_H
