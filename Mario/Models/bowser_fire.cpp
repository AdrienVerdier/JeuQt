#include "bowser_fire.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
bowser_fire::bowser_fire()
{

    move_to_down = false;
    move_to_right = false;
    move_to_left = true;
}

void bowser_fire::collision(Entity *entity, int position)
{

}


void bowser_fire::update()
{
   Alive_Entity::update();
   if(move_to_right) this->coord_x += 3;
   if(move_to_left) this->coord_x -= 3;
}
