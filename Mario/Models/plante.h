#ifndef PLANTE_H
#define PLANTE_H


#include "alive_entity.h"

class Mario;
class plante : public Alive_Entity
{
public:
    plante();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
    bool getTuyau() const;
    void setTuyau(bool value);

    int getCpt_frame() const;
    void setCpt_frame(int value);

private:
    bool tuyau=false;
    int cpt_frame=0;
};


#endif // PLANTE_H
