#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QGraphicsScene>
#include "../Models/interface_visitor.h"
#include <QMap>
#include "game_view_entity.h"
#include "game_view_factory.h"
#include "../Tools/controls.h"

class Game_View : public QGraphicsScene, public Interface_Visitor
{
    public:
        Game_View(QWidget *parent = 0 );
        void paint(Entity *entity);
        QMap<Entity*,QList<Entity*>> get_list_collides();
        void keyPressEvent(QKeyEvent * keyEvent);
        void keyReleaseEvent(QKeyEvent * keyEvent);
        Controls * get_Keys();
    private :
        Game_View_Factory entity_factory;
        QMap<Entity*, Game_View_Entity*> map_Entity_GameViewEntity;
        Controls *controls;

};

#endif // GAME_VIEW_H
