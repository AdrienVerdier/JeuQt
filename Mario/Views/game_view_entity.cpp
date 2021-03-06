#include "game_view_entity.h"
#include<QDebug>


Game_View_Entity::Game_View_Entity()
{

}

Game_View_Entity::Game_View_Entity(QMap<int,QList<QString>> m,int x, int y, int state){
    map_state_step_picture = m;
    this->step_frame = 0;
    this->cpt_tempo = 0;
    this->state_Before = state;
    this->setX(x);
    this->setY(y);
    this->picture  = QPixmap(map_state_step_picture[state_Before][step_frame]);
}

void Game_View_Entity::update_Img(int x, int y, int state)
{

    if (state_Before != state) {
        step_frame = 0;
        cpt_tempo = 0;
    }

    state_Before = state;
    setX(x);
    setY(y);
    picture  = QPixmap(map_state_step_picture[state_Before][step_frame]);
    update();
    if (cpt_tempo == 0)step_frame++;
    cpt_tempo++;
    if(cpt_tempo == 6) cpt_tempo = 0;
    if(step_frame == map_state_step_picture[state_Before].size()) {
        step_frame = 0;
        cpt_tempo = 0;
    }

}

QRectF Game_View_Entity::boundingRect() const
{
    return QRectF(0,0,picture.width(),picture.height());
}

void Game_View_Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->rotate(10);
    painter->drawPixmap(0,0,picture.width(),picture.height(),picture);


}
