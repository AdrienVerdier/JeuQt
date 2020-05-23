#ifndef GAME_VIEW_ENTITY_H
#define GAME_VIEW_ENTITY_H


#include <QGraphicsItem>
#include "../Models/entity.h"
#include <QMap>
#include <QList>
#include <QString>


class Game_View_Entity : QGraphicsItem
{
public:
    Game_View_Entity();



private:
    int step_frame;
    int state_Before;
    QMap<int,QList<QString>> map_state_step_picture;

};

#endif // GAME_VIEW_ENTITY_H
