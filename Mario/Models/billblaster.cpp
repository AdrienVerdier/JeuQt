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
    if (cpt_frame == 30){
        smoke * s = new smoke();
        level->get_alive_entity_list()->push_back(s);
        s->setDisplay(true);
        if(level->getPlayer()->getDistanceOn_X(coord_x)>0)s->setCoordX(coord_x-30);
        if(level->getPlayer()->getDistanceOn_X(coord_x)<0)s->setCoordX(coord_x+55);
        s->setCoordY(coord_y);
        s->setState(0);
        cpt_frame = 0;
    }
    cpt_frame++;
}
