#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <QList>

class Level
{
public:
    Level();
    QList<Entity*> * get_entity_list();

private:
    QList<Entity*> * entity_list;
};

#endif // LEVEL_H
