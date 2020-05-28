#ifndef GAME_VIEW_FACTORY_H
#define GAME_VIEW_FACTORY_H


#include "../Models/goomba.h"
#include "../Models/block.h"
#include "../Models/peach.h"
#include "../Models/mario.h"
#include "game_view_entity.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDir>

class Game_View_Factory
{
public:
    Game_View_Factory();
    Game_View_Entity* create(Entity *e);
    Game_View_Entity* create(Mario *m);
    Game_View_Entity* create(Block *b);
    Game_View_Entity* create(Goomba *g);

};

#endif // GAME_VIEW_FACTORY_H
