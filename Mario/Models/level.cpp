#include "level.h"
#include "mario.h"

Level::Level()
{

    entity_list = new QList<Entity*>();

    /*\     AJOUTS TEMPORAIRES    \*/

    Mario * m = new Mario();
    m->setDisplay(true);
    m->setCoordX(0);
    m->setCoordY(550);
    m->setState(1);
    player = m;

/*
    Mario * m2 = new Mario();
    m2->setDisplay(true);
    m2->setCoordX(35);
    m2->setCoordY(51);
    m2->setState(1);
    entity_list->push_back(m2);
*/

}

QList<Entity *> *Level::get_entity_list()
{
    return entity_list;
}

Mario *Level::getPlayer()
{
  return player;
}
