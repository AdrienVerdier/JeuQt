#include "mario.h"
#include <typeinfo>

Mario::Mario()
{

}

void Mario::setInputs(Controls *c)
{
    input = c;
}

void Mario::collision(Entity *entity, int position)
{
    if (typeid (Block).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (Goomba).name() == typeid(*entity).name()) collisionSpec((Goomba*)entity, position);
}

void Mario::update()
{
    if(input->right && move_to_right) coord_x+= 5;
    if(input->left && move_to_left) coord_x-= 5;
    if(!input->left && !input->right ) state= 0;
    else state = 1;

    this->move_to_up = true;
    this->move_to_right = true;
    this->move_to_down = true;
    this->move_to_left = true;
}

void Mario::collisionSpec(Block *entity, int position)
{
    switch (position) {
        case 0 :
            this->move_to_up = false;
            break;
        case 1:
            this->move_to_right = false;
            break;
        case 2:
            this->move_to_down = false;
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(Goomba *entity, int position)
{
    switch (position) {
        case 0 :
            this->state_dead = true;
        case 1:
            this->state_dead = true;
        case 2:
            this->state_dead = true;
    }
}
