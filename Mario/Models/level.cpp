#include "level.h"
#include "mario.h"
#include "block.h"

Level::Level()
{

    entity_list = new QList<Entity*>();

    /*\     AJOUTS TEMPORAIRES    \*/

    Mario * m = new Mario();
    m->setDisplay(true);
    m->setCoordX(50);
    m->setCoordY(530);
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
    Block * b = new Block();
    b->setDisplay(true);
    b->setCoordX(200);
    b->setCoordY(570);
    b->setState(0);
    entity_list->push_back(b);

    Block * b2 = new Block();
    b2->setDisplay(true);
    b2->setCoordX(0);
    b2->setCoordY(570);
    b2->setState(0);
    entity_list->push_back(b2);

    for(int i=0;i<20;i++){
        entity_list->push_back(new Block());
        entity_list->last()->setDisplay(true);
        entity_list->last()->setCoordX(i*25);
        entity_list->last()->setCoordY(595);
        entity_list->last()->setState(0);


    }

}

QList<Entity *> *Level::get_entity_list()
{
    return entity_list;
}

Mario *Level::getPlayer()
{
  return player;
}
