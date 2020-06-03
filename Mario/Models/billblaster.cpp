#include "billblaster.h"
#include "mario.h"
#include "level.h"

#include <typeinfo>
#include <QDebug>
billblaster::billblaster()
{
    cpt_frame = 0;

}

void billblaster::collision(Entity *entity, int position)
{

}


void billblaster::update()
{
    if (cpt_frame == 1000){
        smoke * s = new smoke();
        level->get_alive_entity_list()->push_back(s);
        s->setDisplay(true);
        if(level->getPlayer()->getDistanceOn_X(coord_x)>0)s->setCoordX(coord_x-30);
        if(level->getPlayer()->getDistanceOn_X(coord_x)<0)s->setCoordX(coord_x+55);
        s->setCoordY(coord_y);
        s->setState(0);

        bool left = true;
        if(level->getPlayer()->getDistanceOn_X(coord_x)<0) left = false;
        bulletbill * b = new bulletbill(left);
        level->get_alive_entity_list()->push_back(b);
        b->setDisplay(true);
        if(level->getPlayer()->getDistanceOn_X(coord_x)>0)b->setCoordX(coord_x-30);
        if(level->getPlayer()->getDistanceOn_X(coord_x)<0)b->setCoordX(coord_x+55);
        b->setCoordY(coord_y);
        b->setState(0);

        cpt_frame = 0;
    }
    cpt_frame++;
}
