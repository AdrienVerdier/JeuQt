#ifndef STAR_H
#define STAR_H


#include "alive_entity.h"

class Mario;
class star : public Alive_Entity
{
public:
    star();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // STAR_H
