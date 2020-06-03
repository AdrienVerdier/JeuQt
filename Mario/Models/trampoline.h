#ifndef TRAMPOLINE_H
#define TRAMPOLINE_H

#include "static_entity.h"

class Trampoline : public Static_Entity
{
public:
    Trampoline();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // TRAMPOLINE_H
