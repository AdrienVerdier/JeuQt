#include "flower.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
flower::flower()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = true;
}

void flower::collision(Entity *entity, int position)
{

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);

}

void flower::collisionSpec(Mario *entity, int position)
{
    this->state_dead = true;
}

void flower::update()
{
    Alive_Entity::update();

}
