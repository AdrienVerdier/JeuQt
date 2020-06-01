#ifndef PIECE_H
#define PIECE_H

#include "alive_entity.h"

class Mario;
class Piece : public Alive_Entity
{
public:
    Piece();
    void collision(Entity* entity, int position) override;
    void collisionSpec(Mario* entity, int position);
    void update() override;
};

#endif // PIECE_H
