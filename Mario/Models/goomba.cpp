#include "goomba.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
Goomba::Goomba()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = true;
}

void Goomba::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();

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

void Goomba::collisionSpec(Mario *entity, int position)
{
    if(position == 0) {
        this->state_dead = true;
        this->display = false;
    } //TODO : le faire mourir
       qInfo() << "collision";
}

void Goomba::update()
{
   if(move_to_right && !move_to_down) this->coord_x += 1;
   if(move_to_left && !move_to_down) this->coord_x -= 1;
   if(move_to_down) this->coord_y += 5;
   move_to_down = true;

}

