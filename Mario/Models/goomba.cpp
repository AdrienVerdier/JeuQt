#include "goomba.h"

Goomba::Goomba()
{

}

void Goomba::collision(Entity *entity, int position)
{
    if(position == 1){
        move_to_left = true;
        move_to_right = false;
    }
    if(position == 2){
        move_to_left = false;
        move_to_right = true;
    }
}

void Goomba::update()
{
   if(move_to_right) this->coord_x =+ 5;
   if(move_to_left) this->coord_x =- 5;
}

