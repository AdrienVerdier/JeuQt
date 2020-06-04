#ifndef BILLBLASTER_H
#define BILLBLASTER_H


#include "alive_entity.h"
#include <QMediaPlayer>

class billblaster  : public Alive_Entity
{
public:
    billblaster();
    void collision(Entity* entity, int position)  override;
    void update() override;
private:
    int cpt_frame;
    QMediaPlayer * bill_blaster_sound;
};

#endif // BILLBLASTER_H
