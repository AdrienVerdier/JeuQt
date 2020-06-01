#ifndef MARIO_H
#define MARIO_H

#include "alive_entity.h"
#include "../Tools/controls.h"
#include "Models/block.h"
#include "Models/goomba.h"
#include "Models/koopa.h"

class Mario : public Alive_Entity
{
public:
    Mario();
    void setInputs(Controls *c);
    void collision(Entity* entity, int position)  override;
    void update() override;
    void collisionSpec(Block* entity, int position);
    void collisionSpec(Goomba* entity, int position);
    void collisionSpec(Koopa* entity, int position);

    int getCptjump() const;


private:
    Controls *input;
    int cptjump;
    bool jump;

};

#endif // MARIO_H
