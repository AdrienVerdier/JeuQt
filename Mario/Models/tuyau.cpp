#include "tuyau.h"
#include "level.h"

Tuyau::Tuyau()
{
    cpt_frame = 0;
}

void Tuyau::collision(Entity *entity, int position)
{

}

void Tuyau::update()
{
    if (cpt_frame == 60){
        plante * p = new plante();
        level->get_alive_entity_list()->prepend(p);
        p->setDisplay(true);
        p->setCoordX(coord_x+10);
        p->setCoordY(coord_y);
        p->setState(0);
        p->setTuyau(true);
        refresh = true;

        cpt_frame = 0;
    }
    cpt_frame++;
}
