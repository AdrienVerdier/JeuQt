#ifndef MARIO_H
#define MARIO_H

#include "alive_entity.h"
#include "../Tools/controls.h"
#include "Models/block.h"
#include "Models/blockgrass.h"
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
#include "Models/mysteryblock.h"
#include "Models/lifeup.h"
#include "Models/star.h"
#include "Models/mushroom.h"
#include "Models/flower.h"
#include "Models/chateau.h"
#include "Models/trampoline.h"
#include "Models/spike.h"
#include "Models/carapace.h"
#include "Models/checkpoint.h"
#include <QMediaPlayer>
class Mario : public Alive_Entity
{
public:
    Mario();
    void setInputs(Controls *c);
    void collision(Entity* entity, int position)  override;
    void update() override;
    void collisionSpec(Block* entity, int position);
    void collisionSpec(BlockGrass* entity, int position);
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
    void collisionSpec(Chateau* entity, int position);
    void collisionSpec(Trampoline* entity, int position);
    void collisionSpec(spike* entity, int position);
    void collisionSpec(mushroom* entity, int position);
    void collisionSpec(lifeup* entity, int position);
    void collisionSpec(star* entity, int position);
    void collisionSpec(flower* entity, int position);
    void collisionSpec(carapace* entity, int position);

    int getCptjump() const;


    bool getOn_ground() const;
    void setOn_ground(bool value);

    bool getContact_thwomp() const;
    void setContact_thwomp(bool value);

    bool getContact_trampoline() const;
    void setContact_trampoline(bool value);

    bool getInvincible() const;
    void setInvincible(bool value);

    int getCptinvincible() const;
    void setCptinvincible(int value);

private:
    Controls *input;
    int cptjump;
    int cptmort =0;
    bool jump;
    bool on_ground;
    bool contact_thwomp;
    bool contact_trampoline=false;
    bool invincible = false;
    bool mort = false;
    int cptinvincible = 0;
    QMediaPlayer * jump_sound;
    QMediaPlayer * coin_sound;
    QMediaPlayer * lifeup_sound;
    QMediaPlayer * powerup_sound;
};

#endif // MARIO_H
