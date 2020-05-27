#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <QList>
#include "mario.h"
#include "block.h"

class Level
{
public:
    Level();
    QList<Entity*> * get_entity_list();
    Mario * getPlayer();

private:
    Mario * player;
    QList<Entity*> * entity_list;
};

#endif // LEVEL_H
