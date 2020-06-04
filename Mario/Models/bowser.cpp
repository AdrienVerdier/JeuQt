#include "bowser.h"

#include "mario.h"
#include "level.h"

#include <typeinfo>
#include <QDebug>
bowser::bowser()
{
    cpt_frame = 0;
    life=2;
}

void bowser::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()){
        if(position == 0){
            if(life >0){
                life--;
            }
            else{
                state_dead=true;
            }
        }
    }
}


void bowser::update()
{

    if(state == 0)state = 1;
    if(state == 2 && cpt_frame==10)state = 0;
    if (cpt_frame >= 0 && cpt_frame <30){
        coord_x +=1;
    }
    if (cpt_frame >= 30 && cpt_frame <60){
        coord_x -=1;
    }
    if (cpt_frame == 60){
        state = 3;
    }
    if(state==3 && cpt_frame<75){
        coord_y -=4;
    }
    if (cpt_frame >= 75 && cpt_frame<90){
        coord_y +=4;
    }
    if (cpt_frame == 90){
        state = 1;
    }
    if (cpt_frame == 120){
        state = 2;
        bulletbill * b = new bulletbill(true);
        level->get_alive_entity_list()->push_back(b);
        b->setDisplay(true);
        b->setCoordX(coord_x-30);;
        b->setCoordY(coord_y+50);
        b->setState(0);

        cpt_frame = 0;
    }
    cpt_frame++;
}
