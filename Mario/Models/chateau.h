#ifndef CHATEAU_H
#define CHATEAU_H

#include "static_entity.h"

class Chateau : public Static_Entity
{
public:
    Chateau();
    void collision(Entity* entity, int position)  override;
    void update() override;
};

#endif // CHATEAU_H
