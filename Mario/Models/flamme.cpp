#include "flamme.h"

#include <typeinfo>
#include <QDebug>
flamme::flamme()
{
    move_to_right = false;
    move_to_left = false;
    move_to_down = false;
}

void flamme::collision(Entity *entity, int position)
{
    QString name = typeid(*entity).name();
    if (name != "5Block") qInfo() << typeid(*entity).name();

}

void flamme::update()
{

}
