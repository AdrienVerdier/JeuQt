#include "koopa.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
Koopa::Koopa()
{
    move_to_right = false;
    move_to_left = true;
    move_to_down = true;
}

void Koopa::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    if(this->getState() != 2 || this->getState() != 3)
    {
        if(position == 1){
            move_to_left = true;
            move_to_right = false;
            state=0;

        }
        if(position == 3){
            move_to_left = false;
            move_to_right = true;
            state=1;

        }
        if(position == 2){
            move_to_down = false;
        }
    }
}

void Koopa::collisionSpec(Mario *entity, int position)
{
    if(state == 2){
        this->state_dead = true;
        this->display = false;
    }
    if(position == 0) {
        state=2;
        move_to_left = false;
        move_to_right = false;
    }
    if(position == 1){
        if(state==2)
        {
            state=3;
            move_to_left = true;
            move_to_right = false;
        }

    }
    if(position == 3){
        if(state==2)
        {
            state=3;
            move_to_left = false;
            move_to_right = true;
        }
    }
}

void Koopa::update()
{
   if(move_to_right && !move_to_down) this->coord_x += 1;
   if(move_to_left && !move_to_down) this->coord_x -= 1;
   if(move_to_down) this->coord_y += 5;
   move_to_down = true;

}
