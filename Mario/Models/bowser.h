#ifndef BOWSER_H
#define BOWSER_H

#include "alive_entity.h"
#include "QMediaPlayer"

class bowser  : public Alive_Entity
{
public:
    bowser();
    void collision(Entity* entity, int position)  override;
    void update() override;
private:
    int cpt_frame;
    int life;
    int shoot=0;
    QMediaPlayer * bowser_fire_sound;
};

#endif // BOWSER_H
