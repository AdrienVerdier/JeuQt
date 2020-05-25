#ifndef ENTITY_H
#define ENTITY_H


#include "interface_visitable.h"

class Interface_Visitor;
class Interface_Visitable;

class Entity : public Interface_Visitable
{
    public:

        Entity();
        Entity(int coord_x ,int coord_y):coord_x(coord_x),coord_y(coord_y){ collision = true;}


        inline bool getCollision() const{
            return collision;
        }
        inline void setCollision(bool value){
            collision = value;
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

        void update();

        void accept(Interface_Visitor *visitor);

        inline void setDisplay(bool d){
            display = d;
        }

        inline bool getDisplay() const{
            return display;
        }

    protected:
        bool display;
        bool collision;
        int coord_x;
        int coord_y;
        int state;


};

#endif // ENTITY_H
