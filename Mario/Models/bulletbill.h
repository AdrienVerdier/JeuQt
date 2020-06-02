#ifndef BULLETBILL_H
#define BULLETBILL_H

#include "alive_entity.h"

class Mario;
class bulletbill : public Alive_Entity
{
public:
    bulletbill(bool left);
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;

    bool getLeft() const;
    void setLeft(bool value);

private:
    bool left;
};
#endif // BULLETBILL_H
