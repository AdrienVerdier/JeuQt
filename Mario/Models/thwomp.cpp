#include "thwomp.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
thwomp::thwomp()
{
    move_to_right = false;
    move_to_left = true;
    move_to_down = true;
}

void thwomp::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();

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

void thwomp::update()
{
   if(move_to_right && !move_to_down) this->coord_x += 1;
   if(move_to_left && !move_to_down) this->coord_x -= 1;
   if(move_to_down) this->coord_y += 5;
   move_to_down = true;

}
