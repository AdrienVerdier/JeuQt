#ifndef GAME_VIEW_FACTORY_H
#define GAME_VIEW_FACTORY_H


#include "../Models/goomba.h"
#include "../Models/block.h"
#include "../Models/peach.h"
#include "../Models/mario.h"
#include "../Models/piece.h"
#include "../Models/koopa.h"
#include "../Models/bulletbill.h"
#include "../Models/billblaster.h"
#include "../Models/smoke.h"
#include "../Models/tuyau.h"
#include "../Models/mysteryblock.h"
#include "../Models/lifeup.h"
#include "../Models/star.h"
#include "../Models/mushroom.h"
#include "../Models/flower.h"
#include "../Models/chateau.h"
#include "../Models/trampoline.h"
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
    Game_View_Entity* create(Koopa *g,int x);
    Game_View_Entity* create(plante *g,int x);
    Game_View_Entity* create(flamme *g,int x);
    Game_View_Entity* create(thwomp *g,int x);
    Game_View_Entity* create(bulletbill *g,int x);
    Game_View_Entity* create(billblaster *g,int x);
    Game_View_Entity* create(smoke *g,int x);
    Game_View_Entity* create(Tuyau *t, int x);
    Game_View_Entity* create(mysteryblock *t, int x);
    Game_View_Entity* create(star *t, int x);
    Game_View_Entity* create(mushroom *t, int x);
    Game_View_Entity* create(lifeup *t, int x);
    Game_View_Entity* create(flower *t, int x);
    Game_View_Entity* create(Chateau *c, int x);
    Game_View_Entity* create(Trampoline *t, int x);
};

#endif // GAME_VIEW_FACTORY_H
