#include "entity.h"

Entity::Entity()
{
    coord_x = 0;
    coord_y = 0;
    collision = true;

}


void Entity::accept(Interface_Visitor visitor) {
    visitor.paint(this);
}
