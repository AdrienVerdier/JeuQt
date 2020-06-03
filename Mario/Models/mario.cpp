#include "mario.h"
#include <typeinfo>
#include <QDebug>
Mario::Mario()
{
    cptjump = 0;
    jump = false;
    setOn_ground(false);
    setContact_thwomp(false);
}

void Mario::setInputs(Controls *c)
{
    input = c;
}

void Mario::collision(Entity *entity, int position)
{
    if (typeid (Block).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (mysteryblock).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (Goomba).name() == typeid(*entity).name()) collisionSpec((Goomba*)entity, position);
    if (typeid (Piece).name() == typeid(*entity).name()) collisionSpec((Piece*)entity, position);
    if (typeid (Koopa).name() == typeid(*entity).name()) collisionSpec((Koopa*)entity, position);
    if (typeid (plante).name() == typeid(*entity).name()) collisionSpec((plante*)entity, position);
    if (typeid (flamme).name() == typeid(*entity).name()) collisionSpec((flamme*)entity, position);
    if (typeid (thwomp).name() == typeid(*entity).name()) collisionSpec((thwomp*)entity, position);
    if (typeid (bulletbill).name() == typeid(*entity).name()) collisionSpec((bulletbill*)entity, position);
    if (typeid (billblaster).name() == typeid(*entity).name()) collisionSpec((billblaster*)entity, position);
    if (typeid (smoke).name() == typeid(*entity).name()) collisionSpec((smoke*)entity, position);
    if (typeid (Tuyau).name() == typeid(*entity).name()) collisionSpec((Tuyau*)entity, position);
    if (typeid (Chateau).name() == typeid(*entity).name()) collisionSpec((Chateau*)entity, position);
    if (typeid (Trampoline).name() == typeid(*entity).name()) collisionSpec((Trampoline*)entity, position);
    if (typeid (spike).name() == typeid(*entity).name()) collisionSpec((spike*)entity, position);
}

void Mario::update()
{
    if(input->right && move_to_right) {
        state = 1;
        coord_x+= 5;
    }
    if(input->left && move_to_left) {
        state = 4;
        coord_x-= 5;
    }
    if(!input->left && !input->right ) state= 0;

    if(move_to_down) {
        coord_y+=5;
        if(coord_y>750){
            state_dead = true;
        }


    }


    if(input->up && cptjump ==0 && !move_to_down){
        jump = true;
    }

    if(jump){

        if(move_to_up){
           if(input->right )state = 3;
           if(input->left )state = 5;
           this->move_to_down = false;
           coord_y-=5;
           cptjump++;
           if(cptjump <= 2){
               setOn_ground(false);
           }
           if(cptjump == 30){
               jump = false;
           }
        }
        else{
            cptjump = 0;
            jump = false;
        }
    }
    else{
        if(!move_to_down) cptjump=0;
        if(cptjump>0) cptjump--;
    }

    this->move_to_right = true;
    this->move_to_down = true;
    if(jump) move_to_down=false;
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
            setOn_ground(true);
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(Chateau *entity, int position)
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
            setOn_ground(true);
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(Tuyau *entity, int position)
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
            setOn_ground(true);
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(billblaster *entity, int position)
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
            setOn_ground(true);
            break;
        case 3:
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(smoke *entity, int position)
{

}

void Mario::collisionSpec(Trampoline *entity, int position)
{
    move_to_down = false;
    switch (position) {
        case 0 :
            break;
        case 1:
            this->move_to_right = false;
            break;
        case 2:
            jump= true;
            cptjump=-20;
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

void Mario::collisionSpec(bulletbill *entity, int position)
{
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
    if(entity->getState() != 2){
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
}

void Mario::collisionSpec(plante *entity, int position)
{
    state_dead = true;
}

void Mario::collisionSpec(flamme *entity, int position)
{
    state_dead = true;
}

void Mario::collisionSpec(spike *entity, int position)
{
    state_dead = true;
}

void Mario::collisionSpec(thwomp *entity, int position)
{
    setContact_thwomp(true);
    switch (position) {
        case 0 :
            if(getOn_ground() && getContact_thwomp()) state_dead = true;
            this->move_to_up = false;
            break;
        case 1:
            this->move_to_right = false;
            break;
        case 2:
            this->move_to_down = false;
            coord_y-=4;
            break;
        case 3:
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

bool Mario::getOn_ground() const
{
    return on_ground;
}

void Mario::setOn_ground(bool value)
{
    on_ground = value;
}

bool Mario::getContact_thwomp() const
{
    return contact_thwomp;
}

void Mario::setContact_thwomp(bool value)
{
    contact_thwomp = value;
}
