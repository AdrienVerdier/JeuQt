#include "goalpole.h"


#include "mario.h"


GoalPole::GoalPole()
{

}

void GoalPole::collision(Entity *entity, int position)
{
   if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
}

void GoalPole::update()
{

}


void GoalPole::collisionSpec(Mario *entity, int position)
{
   // state = 1;
}
