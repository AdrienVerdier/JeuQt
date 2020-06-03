#include "plante.h"

#include "mario.h"
#include <typeinfo>
#include <QDebug>
plante::plante()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = false;
}

void plante::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    if (typeid (carapace).name() == typeid(*entity).name() && entity->getState() == 1) this->state_dead = true;
}
void plante::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
}


void plante::update()
{
    Alive_Entity::update();
    if(tuyau){
        if(getCpt_frame()<10){
            this->coord_y -= 5;
        }
        if(getCpt_frame()>20){
            this->coord_y += 5;
        }
        if(getCpt_frame() == 30){
            state_dead = true;
        }
        setCpt_frame(getCpt_frame()+1);
    }
}

bool plante::getTuyau() const
{
    return tuyau;
}

void plante::setTuyau(bool value)
{
    tuyau = value;
}

int plante::getCpt_frame() const
{
    return cpt_frame;
}

void plante::setCpt_frame(int value)
{
    cpt_frame = value;
}
