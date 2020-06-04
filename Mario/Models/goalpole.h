#ifndef GOALPOLE_H
#define GOALPOLE_H
#include "alive_entity.h"


class Mario;
class GoalPole: public Alive_Entity
{
public:
    GoalPole();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;


};

#endif // GOALPOLE_H
