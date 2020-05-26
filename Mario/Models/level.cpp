#include "level.h"
#include "mario.h"

Level::Level()
{
    entity_list = new QList<Entity*>();

    /*\     AJOUTS TEMPORAIRES    \*/

    Mario * m = new Mario();
    m->setDisplay(true);
    m->setCoordX(100);
    m->setCoordY(100);
    m->setState(1);
    entity_list->push_back(m);


    Mario * m2 = new Mario();
    m2->setDisplay(true);
    m2->setCoordX(110);
    m2->setCoordY(100);
    m2->setState(1);
    entity_list->push_back(m2);


}

QList<Entity *> *Level::get_entity_list()
{
 return entity_list;
}
