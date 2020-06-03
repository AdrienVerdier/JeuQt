#ifndef CARAPACE_H
#define CARAPACE_H

#include "alive_entity.h"
class Mario;
class carapace : public Alive_Entity
{
public:
    carapace();
    void collision(Entity* entity, int position)  override;
    void collisionSpec(Mario* entity, int position);
    void update() override;

    int getCompteur() const;
    void setCompteur(int value);

private:
    int compteur = 0;
};
#endif // CARAPACE_H
