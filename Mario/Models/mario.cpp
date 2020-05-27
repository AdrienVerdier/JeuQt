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
    if(input->right) coord_x+= 5;
    if(input->left) coord_x-= 5;
    if(!input->left && !input->right ) state= 0;
    else state = 1;
}

void Mario::collisionSpec(Block *entity, int position)
{
    switch (position) {
        case 0 :
            this->move_to_up = false;
        case 1:
            this->move_to_right = false;
        case 2:
            this->move_to_down = false;
        case 3:
            this->move_to_left = false;
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
