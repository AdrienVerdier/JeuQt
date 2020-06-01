#include "mario.h"
#include <typeinfo>

Mario::Mario()
{
    cptjump = 0;
    jump = false;

}

void Mario::setInputs(Controls *c)
{
    input = c;
}

void Mario::collision(Entity *entity, int position)
{
    if (typeid (Block).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (Goomba).name() == typeid(*entity).name()) collisionSpec((Goomba*)entity, position);
    if (typeid (Piece).name() == typeid(*entity).name()) collisionSpec((Piece*)entity, position);
    if (typeid (Koopa).name() == typeid(*entity).name()) collisionSpec((Koopa*)entity, position);
}

void Mario::update()
{
    if(input->right && move_to_right) coord_x+= 5;
    if(input->left && move_to_left) coord_x-= 5;
    if(!input->left && !input->right ) state= 0;
    else state = 1;

    if(move_to_down) {
        coord_y+=5;
        if(coord_y>800){
            state_dead = true;
        }


    }




    if(input->up && cptjump ==0 && !move_to_down){
        jump = true;
    }

    if(jump){
        if(move_to_up){
          this->move_to_down = false;
           coord_y-=5;
           cptjump++;
           if(cptjump == 20){
               jump = false;
           }
        }
        else{
            cptjump = 0;
            jump = false;
        }
    }
    else{
        if(cptjump>0) cptjump--;
    }




     this->move_to_right = true;
     this->move_to_down = true;
    if(jump ) move_to_down=false;
     this->move_to_left = true;
     this->move_to_up = true;


}

void Mario::collisionSpec(Block *entity, int position)
{
    switch (position) {
        case 0 :
            this->move_to_up = false;
            break;
        case 1:
            this->move_to_right = false;
            break;
        case 2:
            this->move_to_down = false;
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(Goomba *entity, int position)
{
    move_to_down = false;
    switch (position) {
        case 0 :
           state_dead = true;
            break;
        case 1:
            state_dead = true;
            this->move_to_right = false;
            break;
        case 2:
        jump= true;
        cptjump=0;
        break;
    case 3:
        state_dead = true;
        this->move_to_left = false;
        break;
    }
}

void Mario::collisionSpec(Koopa *entity, int position)
{
    move_to_down = false;
    switch (position) {
        case 0 :
           state_dead = true;
            break;
        case 1:
            state_dead = true;
            this->move_to_right = false;
            break;
        case 2:
            jump= true;
            cptjump=0;
            break;
    case 3:
        state_dead = true;
        this->move_to_left = false;
        break;
    }
}

void Mario::collisionSpec(Piece *entity, int position)
{

}

int Mario::getCptjump() const
{
    return cptjump;
}
