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
    else
    {
        if(position == 2){
            move_to_down = false;
        }
        if(state != 2 && state != 3)
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
        }
    }

}

void Koopa::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
    if(state == 2 && position == 0){
        this->state_dead = true;
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
   Alive_Entity::update();
   if(move_to_right && !move_to_down) this->coord_x += 1;
   if(move_to_left && !move_to_down) this->coord_x -= 1;
   if(move_to_down) this->coord_y += 5;
   move_to_down = true;

}
