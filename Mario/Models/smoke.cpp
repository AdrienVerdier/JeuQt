#include "smoke.h"

smoke::smoke()
{
   cpt_frame=0;
}

void smoke::collision(Entity *entity, int position)
{

}

void smoke::update()
{
    if(cpt_frame == 12){
        state_dead = true;
    }
    cpt_frame++;

}
