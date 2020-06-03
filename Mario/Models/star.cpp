#include "star.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
star::star()
{
    move_to_right = true;
    move_to_left = false;
    move_to_down = false;
}

void star::collision(Entity *entity, int position)
{

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    if(position == 1){
        move_to_left = true;
        move_to_right = false;
    }
    if(position == 3){
        move_to_left = false;
        move_to_right = true;
    }
}

void star::collisionSpec(Mario *entity, int position)
{
    this->state_dead = true;
}

void star::update()
{
    Alive_Entity::update();
    if(move_to_right && !move_to_down) this->coord_x += 1;
    if(move_to_left && !move_to_down) this->coord_x -= 1;
}
