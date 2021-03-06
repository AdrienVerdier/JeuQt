#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QGraphicsScene>
#include "../Models/interface_visitor.h"
#include <QMap>
#include "game_view_entity.h"
#include "game_view_factory.h"
#include "../Tools/controls.h"
#include <QLabel>

class Level_Controller;
class Game_View : public QGraphicsScene, public Interface_Visitor
{
    public:
        Game_View(Level_Controller* parent);
        void paint(Entity *entity);
        QMap<Entity*, QMap<Entity*,int>> get_list_collides();
        void keyPressEvent(QKeyEvent * keyEvent);
        void keyReleaseEvent(QKeyEvent * keyEvent);
        Controls * get_Keys();
        void reset();
        void setMx(int value);
        void update_HUD(int score, int vie);

        int getXLeftLimit() const;
        void setXLeftLimit(int value);

private :
        Level_Controller *controler;
        Game_View_Factory entity_factory;
        QMap<Entity*, Game_View_Entity*> map_Entity_GameViewEntity;
        Controls *controls;
        QMap<QString,int> E1;
        QMap<QString,int> E2;
        int Mx;
        int xLeftLimit;
        QLabel *score;
        QGraphicsPixmapItem *pieceHUD;
        QLabel *vies;
        QGraphicsPixmapItem *viesHUD;
        QGraphicsPixmapItem *background;
        int x;
        bool updateB;
        int nbScore;
        int nbVies;


        void fillPoints(Game_View_Entity *e1, Game_View_Entity *e2);


};

#endif // GAME_VIEW_H
