#include "goomba.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
Goomba::Goomba()
{
    move_to_right = false;
    move_to_left = true;
    move_to_down = true;
}

void Goomba::collision(Entity *entity, int position)
{

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);

    if (typeid (carapace).name() == typeid(*entity).name() && entity->getState() == 1) this->state_dead = true;
    if (typeid (bulletbill).name() != typeid(*entity).name() && typeid (bowser_fire).name() != typeid(*entity).name() && typeid (Piece).name() != typeid(*entity).name()) {
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

void Goomba::collisionSpec(Mario *entity, int position)
{

    if(entity->getInvincible()) this->state_dead = true;
    if(position == 0) {
        this->state_dead = true;
    }
}

void Goomba::update()
{
   Alive_Entity::update();
   if(move_to_right && !move_to_down) this->coord_x += 1;
   if(move_to_left && !move_to_down) this->coord_x -= 1;
   if(move_to_down) this->coord_y += 5;
   move_to_down = true;

}

