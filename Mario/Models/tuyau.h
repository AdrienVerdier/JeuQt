#ifndef TUYAU_H
#define TUYAU_H

#include "alive_entity.h"

class Tuyau : public Alive_Entity
{
public:
    Tuyau();
    void collision(Entity* entity, int position)  override;
    void update() override;
private:
    int cpt_frame;
};

#endif // TUYAU_H
