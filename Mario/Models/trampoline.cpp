#include "trampoline.h"

Trampoline::Trampoline()
{

}

void Trampoline::collision(Entity *entity, int position)
{
    if(position == 0)state=1;
}

void Trampoline::update()
{
    if(state==1)setCompteur(getCompteur()+1);
    if(getCompteur()==20){
        state=0;
        setCompteur(0);
    }
}

int Trampoline::getCompteur() const
{
    return compteur;
}

void Trampoline::setCompteur(int value)
{
    compteur = value;
}
