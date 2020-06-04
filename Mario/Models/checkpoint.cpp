#include "checkpoint.h"
#include "mario.h"


CheckPoint::CheckPoint()
{
    cpt_frame = 0;
}

void CheckPoint::collision(Entity *entity, int position)
{
   if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
}

void CheckPoint::update()
{

}


void CheckPoint::collisionSpec(Mario *entity, int position)
{
    state = 1;
}
