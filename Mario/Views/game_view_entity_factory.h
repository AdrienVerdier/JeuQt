#ifndef GAME_VIEW_ENTITY_FACTORY_H
#define GAME_VIEW_ENTITY_FACTORY_H

#import "../Models/entity.h"
#import "game_view_entity.h"

class Game_View_Entity_Factory
{
public:
    Game_View_Entity_Factory();
    Game_View_Entity create(Entity entity);
};

#endif // GAME_VIEW_ENTITY_FACTORY_H
