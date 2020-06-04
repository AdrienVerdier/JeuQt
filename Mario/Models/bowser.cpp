#include "bowser.h"

#include "mario.h"
#include "level.h"

#include <typeinfo>
#include <QDebug>
bowser::bowser()
{
    cpt_frame = 0;
    life=3;
    bowser_fire_sound = new QMediaPlayer();
    bowser_fire_sound->setMedia(QUrl("qrc:/son/son/bowser_fire.mp3"));
    bowser_fire_sound->setVolume(30);
}

void bowser::collision(Entity *entity, int position)
{
    if (typeid (Mario).name() == typeid(*entity).name()){
        if(position == 0){
            if(life >0){
                life--;
            }
            else{
                state=4;
                dead = true;
            }
        }
    }
    if(dead){
        if(typeid (Block).name() == typeid(*entity).name() || typeid (BlockGrass).name() == typeid(*entity).name()){
            move_to_down = false;
        }
    }
}


void bowser::update()
{
    if(dead){
        cpt_frame_dead++;
        if(cpt_frame_dead == 40 )state_dead=true;
    }
    else{
        if(state == 0)state = 1;
        if(state == 2 && cpt_frame==10)state = 0;
        if (cpt_frame >= 0 && cpt_frame <30){
            coord_x +=1;
        }
        if (cpt_frame >= 30 && cpt_frame <60){
            coord_x -=1;
        }
        if (cpt_frame == 60){
            state = 3;
        }
        if(state==3 && cpt_frame<75){
            coord_y -=4;
        }
        if (cpt_frame == 75 ){
            if(bowser_fire_sound->state() == QMediaPlayer::PlayingState)bowser_fire_sound->setPosition(0);
            if(bowser_fire_sound->state() == QMediaPlayer::StoppedState)bowser_fire_sound->play();
            bowser_fire * b = new bowser_fire();
            level->get_alive_entity_list()->push_back(b);
            b->setDisplay(true);
            if(shoot ==0){
                state = 2;
                shoot =1;
                b->setCoordX(coord_x-30);;
                b->setCoordY(coord_y+50);
                b->setState(0);
            }
            else{
                state = 5;
                shoot =0;
                b->setCoordX(coord_x+50);;
                b->setCoordY(coord_y);
                b->setState(1);
            }
        }
        if (cpt_frame >= 75 && cpt_frame<90){
            coord_y +=4;
        }
        if (cpt_frame == 90){
            state = 1;
        }
        if (cpt_frame == 120){
            if(bowser_fire_sound->state() == QMediaPlayer::PlayingState)bowser_fire_sound->setPosition(0);
            if(bowser_fire_sound->state() == QMediaPlayer::StoppedState)bowser_fire_sound->play();
            state = 2;
            bowser_fire * b = new bowser_fire();
            level->get_alive_entity_list()->push_back(b);
            b->setDisplay(true);
            b->setCoordX(coord_x-30);;
            b->setCoordY(coord_y+50);
            b->setState(0);

            cpt_frame = 0;
        }
        cpt_frame++;
    }

}
