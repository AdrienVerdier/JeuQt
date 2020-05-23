#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QGraphicsScene>
#include "../Models/interface_visitor.h"
#include <QMap>
#include "game_view_entity.h"


class Game_View : public QGraphicsScene, public Interface_Visitor
{
    public:
        Game_View();
        void paint(Entity entity) override;
    private :

        QMap<Entity*, Game_View_Entity*> map_Entity_GameViewEntity;
};

#endif // GAME_VIEW_H
