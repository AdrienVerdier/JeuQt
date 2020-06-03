#include "alive_entity.h"
#include "QDebug"
Alive_Entity::Alive_Entity()
{
    move = true;
}

void Alive_Entity::collision(Entity *entity, int position)
{

}

void Alive_Entity::update()
{
    if(coord_y>750){
        state_dead = true;
    }
}

Alive_Entity::~Alive_Entity()
{

}
