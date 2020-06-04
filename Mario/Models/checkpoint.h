#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include "alive_entity.h"


class Mario;
class CheckPoint: public Alive_Entity
{
public:
    CheckPoint();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
private:
    int cpt_frame;
};

#endif // CHECKPOINT_H
