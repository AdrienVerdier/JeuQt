#include "mysteryblock.h"
#include "mario.h"
#include "level.h"
#include <typeinfo>
#include <QDebug>
mysteryblock::mysteryblock()
{

}

void mysteryblock::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()) {
        if(!non_static && state==0){
            if(position==2){
                setNon_static(true);
                setMove_to_up(true);
            }
        }
    }
}

void mysteryblock::update()
{
    if(getMove_to_up() && getCompteur() < 5){
        setCompteur(getCompteur()+1);
        coord_y-=5;
    }
    if(getMove_to_up() && getCompteur() >= 5){
        setMove_to_up(false);
        setMove_to_down(true);
        setCompteur(0);
        setState(1);
        flower *c= new flower();
        level->get_alive_entity_list()->push_back(c);
        c->setDisplay(true);
        c->setCoordX(coord_x);
        c->setCoordY(coord_y-4);
        c->setState(0);

    }
    if(getMove_to_down() && getCompteur() < 5){
        setCompteur(getCompteur()+1);
        coord_y+=5;
    }
    if(getMove_to_down() && getCompteur() >= 5){
        setMove_to_up(false);
        setMove_to_down(false);
    }
}

int mysteryblock::getCompteur() const
{
    return compteur;
}

void mysteryblock::setCompteur(int value)
{
    compteur = value;
}

bool mysteryblock::getNon_static() const
{
    return non_static;
}

void mysteryblock::setNon_static(bool value)
{
    non_static = value;
}

bool mysteryblock::getMove_to_down() const
{
    return move_to_down;
}

void mysteryblock::setMove_to_down(bool value)
{
    move_to_down = value;
}

bool mysteryblock::getMove_to_up() const
{
    return move_to_up;
}

void mysteryblock::setMove_to_up(bool value)
{
    move_to_up = value;
}
