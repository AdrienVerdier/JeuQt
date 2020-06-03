#include "bulletbill.h"

#include "mario.h"

#include <typeinfo>
#include <QDebug>
bulletbill::bulletbill(bool left)
{

    move_to_down = false;
    setLeft(left);
    if(left){
        move_to_right = false;
        move_to_left = true;
    }
    else{
        move_to_right = true;
        move_to_left = false;
    }
}

void bulletbill::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
}

void bulletbill::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
    if(position == 0) {
        this->state_dead = true;
    }
}

void bulletbill::update()
{
   Alive_Entity::update();
   if(move_to_right) this->coord_x += 5;
   if(move_to_left) this->coord_x -= 5;
   if(!getLeft()){
        setState(1);
   }
}

bool bulletbill::getLeft() const
{
    return left;
}

void bulletbill::setLeft(bool value)
{
    left = value;
}
