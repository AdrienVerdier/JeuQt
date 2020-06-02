#include "thwomp.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
thwomp::thwomp()
{
    move_to_down = true;
}

void thwomp::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();
    if(position == 2 && typeid (Mario).name() != typeid(*entity).name()){
        move_to_down = false;
        move_to_up = true;
        state=1;
    }
}

void thwomp::update()
{
   if(getInitial_y()==-1) setInitial_y(this->coord_y);
   if(move_to_down) this->coord_y += 4;
   if(move_to_up) this->coord_y -= 4;
   if(this->coord_y <= initial_y)
   {
       move_to_up = false;
       move_to_down = true;
       state=0;
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
