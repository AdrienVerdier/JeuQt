#include "thwomp.h"
#include "mario.h"
#include "level.h"

#include <typeinfo>
#include <QDebug>
thwomp::thwomp()
{
    move_to_down = true;
}

void thwomp::collision(Entity *entity, int position)
{
    if(position == 2 && typeid (Block).name() != typeid(*entity).name() && typeid (bulletbill).name() != typeid(*entity).name() && typeid (Mario).name() != typeid(*entity).name() && !getOn_block()){
        move_to_down = false;
        move_to_up = true;
        state=1;
    }
    if(position == 2 && typeid (Block).name() == typeid(*entity).name() && !getOn_block()){
        move_to_down = false;
        move_to_up = false;
        setOn_block(true);
        setCompteur(0);
    }
}

void thwomp::update()
{
   if(getInitial_y()==-1) setInitial_y(this->coord_y);
   if(level->getPlayer()->getDistanceOn_X(coord_x)>0 && level->getPlayer()->getDistanceOn_X(coord_x)<100 || level->getPlayer()->getDistanceOn_X(coord_x)<0 && level->getPlayer()->getDistanceOn_X(coord_x)>-200 || coord_y != getInitial_y())
   {
       if(move_to_up) this->coord_y -= 4;
       if(!getOn_block())
       {
           if(move_to_down) {
               state=0;
               this->coord_y += 4;
           }
           if(this->coord_y <= initial_y)
           {
               move_to_up = false;
               move_to_down = true;
               state=0;
           }
       }
       else{
           setCompteur(getCompteur()+1);
       }
       if(getCompteur() == 50)
       {
           move_to_up = true;
           state=1;
       }
       if(getCompteur() == 55)
       {
           setOn_block(false);
           setCompteur(0);
       }
   }
    else{
       state=2;
   }
}

int thwomp::getInitial_y() const
{
    return initial_y;
}

void thwomp::setInitial_y(int value)
{
    initial_y = value;
}

bool thwomp::getOn_block() const
{
    return on_block;
}

void thwomp::setOn_block(bool value)
{
    on_block = value;
}

int thwomp::getCompteur() const
{
    return compteur;
}

void thwomp::setCompteur(int value)
{
    compteur = value;
}
