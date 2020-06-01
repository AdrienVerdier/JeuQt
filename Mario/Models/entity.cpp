#include "entity.h"
#include "interface_visitor.h"

Entity::Entity()
{
    coord_x = 0;
    coord_y = 0;
    collision_active = true;
    display = true;
    state_dead = false;


}


void Entity::accept(Interface_Visitor *visitor) {

    visitor->paint(this);
}
