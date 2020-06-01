#ifndef GAME_VIEW_FACTORY_H
#define GAME_VIEW_FACTORY_H


#include "../Models/goomba.h"
#include "../Models/block.h"
#include "../Models/peach.h"
#include "../Models/mario.h"
#include "../Models/piece.h"
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
    Game_View_Entity* create(Entity *e,int x);
    Game_View_Entity* create(Mario *m,int x);
    Game_View_Entity* create(Block *b,int x);
    Game_View_Entity* create(Goomba *g,int x);
    Game_View_Entity* create(Piece *p, int x);

};

#endif // GAME_VIEW_FACTORY_H
