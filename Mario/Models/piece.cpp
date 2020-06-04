#include "piece.h"
#include "mario.h"
#include "level.h"

#include <typeinfo>
#include <QDebug>
Piece::Piece()
{

}

void Piece::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();

    if (typeid (Mario).name() == typeid(*entity).name()) collisionSpec((Mario*) entity, position);
}

void Piece::collisionSpec(Mario *entity, int position)
{

    this->state_dead = true;
    level->SetScore(level->getScore()+1);
    if(level->getScore()==100){
        level->SetNbVie(level->getNbVie()+1);
        level->SetScore(0);
    }

}

void Piece::update()
{
    //Alive_Entity::update();

}
