#include "mushroom.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
mushroom::mushroom()
{
    move_to_right = true;
    move_to_left = false;
    move_to_down = false;
   cpt_frame++;
}

void mushroom::collision(Entity *entity, int position)
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
    if(position == 2){
        move_to_down = false;
    }

}

void mushroom::collisionSpec(Mario *entity, int position)
{
    this->state_dead = true;
}

void mushroom::update()
{
    Alive_Entity::update();
    if(cpt_frame<10) this->coord_y -= 5;
    else{
        if(move_to_down) this->coord_y += 5;
        else{
            if(move_to_right && !move_to_down) this->coord_x += 1;
            if(move_to_left && !move_to_down) this->coord_x -= 1;
        }

    }
    if (cpt_frame<40)cpt_frame++;



    move_to_down = true;
}
