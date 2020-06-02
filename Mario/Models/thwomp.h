#ifndef THWOMP_H
#define THWOMP_H

#include "alive_entity.h"

class thwomp : public Alive_Entity
{
public:
    thwomp();
    void collision(Entity* entity, int position)  override;
    void update() override;
    int getInitial_y() const;
    void setInitial_y(int value);

private:
    int initial_y=-1;
};

#endif // THWOMP_H
