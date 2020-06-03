#ifndef BILLBLASTER_H
#define BILLBLASTER_H


#include "static_entity.h"

class billblaster  : public Static_Entity
{
public:
    billblaster();
    void collision(Entity* entity, int position)  override;
    void update() override;

};

#endif // BILLBLASTER_H
