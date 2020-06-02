#ifndef MYSTERYBLOCK_H
#define MYSTERYBLOCK_H

#include "static_entity.h"

class mysteryblock  : public Static_Entity
{
public:
    mysteryblock();
    void collision(Entity* entity, int position)  override;
    void update() override;
    int getCompteur() const;
    void setCompteur(int value);

    bool getNon_static() const;
    void setNon_static(bool value);

    bool getMove_to_down() const;
    void setMove_to_down(bool value);

    bool getMove_to_up() const;
    void setMove_to_up(bool value);

private:
    int compteur=0;
    bool non_static=false;
    bool move_to_down = false;
    bool move_to_up = false;
};

#endif // MYSTERYBLOCK_H
