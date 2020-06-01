#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <QList>
#include "mario.h"
#include "block.h"
#include "goomba.h"

class Level
{
public:
    Level();
    QList<Entity*> * get_entity_list();
    QList<Entity*> * get_alive_entity_list();
    Mario * getPlayer();

private:
    Mario * player;
    QList<Entity*> * entity_list;
     QList<Entity*> * alive_entity_list;
};

#endif // LEVEL_H
