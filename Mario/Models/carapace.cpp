#include "carapace.h"
#include "mario.h"

#include <typeinfo>
#include <QDebug>
carapace::carapace()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = true;
}

void carapace::collision(Entity *entity, int position)
{
    if (typeid (carapace).name() == typeid(*entity).name() && entity->getState() == 1) this->state_dead = true;
    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
    else
    {
        if(position == 2){
            move_to_down = false;
        }
        if(position == 1 && state == 1) {
            move_to_right = false;
            move_to_left = true;
        }
        if(position == 3 && state == 1) {
            move_to_right = true;
            move_to_left = false;
        }
    }
}
void carapace::collisionSpec(Mario *entity, int position)
{
    if(entity->getInvincible()) this->state_dead = true;
    if(position == 0 && state == 0) {
        this->state_dead = true;
    }
    if(position == 0 && state == 1) {
        this->state = 0;
        move_to_right = false;
        move_to_left = false;
    }
    if(position == 1) {
        state=1;
        move_to_right = false;
        move_to_left = true;
    }
    if(position == 3) {
        state=1;
        move_to_right = true;
        move_to_left = false;
    }
}
void carapace::update()
{
    Alive_Entity::update();
    if(move_to_right && !move_to_down) this->coord_x += 3;
    if(move_to_left && !move_to_down) this->coord_x -= 3;
    if(move_to_down) this->coord_y += 5;
    if(state==0)setCompteur(0);
    else setCompteur(getCompteur()+1);
    move_to_down = true;

}

int carapace::getCompteur() const
{
    return compteur;
}

void carapace::setCompteur(int value)
{
    compteur = value;
}
