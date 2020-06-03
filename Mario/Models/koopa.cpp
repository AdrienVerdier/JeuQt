#include "koopa.h"
#include "mario.h"
#include "level.h"

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

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    if (typeid (carapace).name() == typeid(*entity).name() && entity->getState() == 1) this->state_dead = true;
    if (typeid (bulletbill).name() != typeid(*entity).name()) {
        if(position == 2){
            move_to_down = false;
        }
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

void Koopa::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
    if(position == 0) {
        carapace * c = new carapace();
        level->get_alive_entity_list()->push_back(c);
        c->setDisplay(true);
        c->setCoordX(coord_x);
        c->setCoordY(coord_y);
        c->setState(0);
        this->state_dead = true;
    }
    if(position == 1){
        move_to_left = true;
        move_to_right = false;

    }
    if(position == 3){
        move_to_left = false;
        move_to_right = true;
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
