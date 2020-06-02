#ifndef MARIO_H
#define MARIO_H

#include "alive_entity.h"
#include "../Tools/controls.h"
#include "Models/block.h"
#include "Models/goomba.h"
#include "Models/koopa.h"
#include "Models/piece.h"
#include "Models/plante.h"
#include "Models/flamme.h"
#include "Models/thwomp.h"
#include "Models/bulletbill.h"
#include "Models/billblaster.h"
#include "Models/smoke.h"
#include "Models/tuyau.h"

class Mario : public Alive_Entity
{
public:
    Mario();
    void setInputs(Controls *c);
    void collision(Entity* entity, int position)  override;
    void update() override;
    void collisionSpec(Block* entity, int position);
    void collisionSpec(Goomba* entity, int position);
    void collisionSpec(Piece* piece, int position);
    void collisionSpec(Koopa* entity, int position);
    void collisionSpec(plante* entity, int position);
    void collisionSpec(flamme* entity, int position);
    void collisionSpec(thwomp* entity, int position);
    void collisionSpec(bulletbill* entity, int position);
    void collisionSpec(billblaster* entity, int position);
    void collisionSpec(smoke* entity, int position);
    void collisionSpec(Tuyau* entity, int position);

    int getCptjump() const;


    bool getOn_ground() const;
    void setOn_ground(bool value);

    bool getContact_thwomp() const;
    void setContact_thwomp(bool value);

private:
    Controls *input;
    int cptjump;
    bool jump;
    bool on_ground;
    bool contact_thwomp;
};

#endif // MARIO_H
