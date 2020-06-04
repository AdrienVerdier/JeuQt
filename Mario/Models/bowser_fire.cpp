#include "bowser_fire.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
bowser_fire::bowser_fire()
{

}

void bowser_fire::collision(Entity *entity, int position)
{

}


void bowser_fire::update()
{
   Alive_Entity::update();
   if(state==0) this->coord_x -= 3;
   if(state==1) this->coord_y -= 3;
   if(this->coord_y<-50) state_dead = true;
}
