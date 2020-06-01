#ifndef ENTITY_H
#define ENTITY_H


#include "interface_visitable.h"

class Interface_Visitor;
class Interface_Visitable;

class Entity : public Interface_Visitable
{
    public:

        Entity();
        Entity(int coord_x ,int coord_y):coord_x(coord_x),coord_y(coord_y){ collision_active = true;}

        inline int getDistanceOn_X(Entity* entity){return entity->coord_x - this->coord_x;}
        inline int getDistanceOn_Y(Entity* entity){return entity->coord_y - this->coord_y;}

        inline bool getCollision() const{
            return collision_active;
        }
        inline void setCollision(bool value){
            collision_active = value;
        }

        inline int getCoordX() const{
            return coord_x;
        }
        inline void setCoordX(int value){
            coord_x = value;
        }


        inline int getCoordY() const{
            return coord_y;
        }
        inline void setCoordY(int value){
            coord_y = value;
        }


        inline int getState() const{
            return state;
        }
        inline void setState(int value){
            state = value;
        }


        inline int getDead() const{
            return state_dead;
        }

        virtual void update() =0;
        virtual void collision(Entity* entity, int position)=0;

        void accept(Interface_Visitor *visitor);

        inline void setDisplay(bool d){
            display = d;
        }

        inline bool getDisplay() const{
            return display;
        }

    protected:
        bool display;
        bool collision_active;
        int coord_x;
        int coord_y;
        int state;
        bool state_dead;


};

#endif // ENTITY_H
