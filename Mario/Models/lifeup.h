#ifndef LIFEUP_H
#define LIFEUP_H


#include "alive_entity.h"

class Mario;
class lifeup : public Alive_Entity
{
public:
    lifeup();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // LIFEUP_H
