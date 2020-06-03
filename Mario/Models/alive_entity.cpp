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

void Alive_Entity::setLevel(Level *value)
{
    level = value;
}

bool Alive_Entity::getMove_to_up() const
{
    return move_to_up;
}

void Alive_Entity::setMove_to_up(bool value)
{
    move_to_up = value;
}
