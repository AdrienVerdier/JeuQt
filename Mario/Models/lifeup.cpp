#include "lifeup.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
lifeup::lifeup()
{
    move_to_right = true;
    move_to_left = false;
    move_to_down = false;
}

void lifeup::collision(Entity *entity, int position)
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

void lifeup::collisionSpec(Mario *entity, int position)
{
    this->state_dead = true;
    this->display = false;
}

void lifeup::update()
{
    if(move_to_right && !move_to_down) this->coord_x += 1;
    if(move_to_left && !move_to_down) this->coord_x -= 1;
}
