#ifndef GAME_VIEW_ENTITY_H
#define GAME_VIEW_ENTITY_H


#include <QGraphicsItem>
#include "../Models/entity.h"
#include <QMap>
#include <QList>
#include <QString>
#include <QPainter>

class Game_View_Entity : public QGraphicsItem
{
public:
    Game_View_Entity();
    Game_View_Entity(QMap<int,QList<QString>> m,int x, int y, int state);

    void update_Img(int x, int y, int state);
    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) ;



private:
    int step_frame;
    int state_Before;
    int cpt_tempo;
    QMap<int,QList<QString>> map_state_step_picture;
    QPixmap picture;

};

#endif // GAME_VIEW_ENTITY_H
