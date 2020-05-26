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
    if (typeid (Block).name() == typeid(*entity).name()) collision((Block*)entity, position);
    if (typeid (Goomba).name() == typeid(*entity).name()) collision((Goomba*)entity, position);
}

void Mario::collision(Block *entity, int position)
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

void Mario::collision(Goomba *entity, int position)
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
