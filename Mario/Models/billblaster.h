#ifndef BILLBLASTER_H
#define BILLBLASTER_H


#include "alive_entity.h"

class billblaster  : public Alive_Entity
{
public:
    billblaster();
    void collision(Entity* entity, int position)  override;
    void update() override;
private:
    int cpt_frame;
};

#endif // BILLBLASTER_H
