#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QGraphicsScene>
#include "../Models/interface_visitor.h"
#include <QMap>
#include "game_view_entity.h"
#include "game_view_factory.h"
#include "../Tools/controls.h"
#include <QLabel>

class Game_View : public QGraphicsScene, public Interface_Visitor
{
    public:
        Game_View(QWidget *parent = 0 );
        void paint(Entity *entity);
        QMap<Entity*, QMap<Entity*,int>> get_list_collides();
        void keyPressEvent(QKeyEvent * keyEvent);
        void keyReleaseEvent(QKeyEvent * keyEvent);
        Controls * get_Keys();
        void reset();
        void setMx(int value);

private :
        Game_View_Factory entity_factory;
        QMap<Entity*, Game_View_Entity*> map_Entity_GameViewEntity;
        Controls *controls;
        QMap<QString,int> E1;
        QMap<QString,int> E2;
        int Mx;
        QLabel *score;
        QGraphicsPixmapItem *pieceHUD;
        QLabel *vies;
        QGraphicsPixmapItem *viesHUD;

        void fillPoints(Game_View_Entity *e1, Game_View_Entity *e2);


};

#endif // GAME_VIEW_H
