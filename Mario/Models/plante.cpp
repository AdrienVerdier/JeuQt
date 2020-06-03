#include "plante.h"

#include "mario.h"
#include <typeinfo>
#include <QDebug>
plante::plante()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = false;
}

void plante::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    if (typeid (carapace).name() == typeid(*entity).name() && entity->getState() == 1) this->state_dead = true;
}
void plante::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
}


void plante::update()
{
    Alive_Entity::update();
}
