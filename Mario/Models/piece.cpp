#include "piece.h"
#include "mario.h"

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
    if(position == 0) {
        this->state_dead = true;

    }
    if(position == 1) {
        this->state_dead = true;

    }
    if(position == 2) {
        this->state_dead = true;

    }
    if(position == 3) {
        this->state_dead = true;

    }
    qInfo() << "collision";
}

void Piece::update()
{
    //Alive_Entity::update();

}
