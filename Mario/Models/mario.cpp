#include "mario.h"
#include <typeinfo>
#include <QDebug>
#include <QSound>
#include <QMediaPlayer>
#include <QSoundEffect>
#include "level.h"
Mario::Mario()
{
    cptjump = 0;
    cptPetit=90;
    jump = false;
    setOn_ground(false);
    setContact_thwomp(false);
    jump_sound = new QMediaPlayer();
    jump_sound->setMedia(QUrl("qrc:/son/son/mario_jump.mp3"));
    jump_sound->setVolume(30);
    lifeup_sound = new QMediaPlayer();
    lifeup_sound->setMedia(QUrl("qrc:/son/son/lifeup.mp3"));
    lifeup_sound->setVolume(30);
    coin_sound = new QMediaPlayer();
    coin_sound->setMedia(QUrl("qrc:/son/son/coin.mp3"));
    coin_sound->setVolume(30);
    powerup_sound = new QMediaPlayer();
    powerup_sound->setMedia(QUrl("qrc:/son/son/power_up.mp3"));
    powerup_sound->setVolume(30);
    mario_die_sound = new QMediaPlayer();
    mario_die_sound->setMedia(QUrl("qrc:/son/son/mario_die.mp3"));
    mario_die_sound->setVolume(30);
    game_over_sound = new QMediaPlayer();
    game_over_sound->setMedia(QUrl("qrc:/son/son/game_over.mp3"));
    game_over_sound->setVolume(30);
    victory_sound = new QMediaPlayer();
    victory_sound->setMedia(QUrl("qrc:/son/son/victory.mp3"));
    victory_sound->setVolume(30);
    background_sound = new QMediaPlayer();
    background_sound->setMedia(QUrl("qrc:/son/son/background.mp3"));
    background_sound->setVolume(10);
    star_sound = new QMediaPlayer();
    star_sound->setMedia(QUrl("qrc:/son/son/star.mp3"));
    star_sound->setVolume(30);
}

Mario::~Mario()
{
    delete background_sound;
    delete jump_sound;
    delete coin_sound;
    delete lifeup_sound;
    delete powerup_sound;
    delete mario_die_sound;
    delete game_over_sound;
    delete victory_sound;
    delete star_sound;
}

void Mario::setInputs(Controls *c)
{
    input = c;
}

void Mario::collision(Entity *entity, int position)
{
    if(!goal && !mort && cptPetit>80 )
    {

    if (typeid (Goomba).name() == typeid(*entity).name()) collisionSpec((Goomba*)entity, position);
    if (typeid (Koopa).name() == typeid(*entity).name()) collisionSpec((Koopa*)entity, position);
    if (typeid (plante).name() == typeid(*entity).name()) collisionSpec((plante*)entity, position);
    if (typeid (flamme).name() == typeid(*entity).name()) collisionSpec((flamme*)entity, position);
    if (typeid (thwomp).name() == typeid(*entity).name()) collisionSpec((thwomp*)entity, position);
    if (typeid (bulletbill).name() == typeid(*entity).name()) collisionSpec((bulletbill*)entity, position);
    if (typeid (smoke).name() == typeid(*entity).name()) collisionSpec((smoke*)entity, position);
    if (typeid (Chateau).name() == typeid(*entity).name()) collisionSpec((Chateau*)entity, position);

    if (typeid (spike).name() == typeid(*entity).name()) collisionSpec((spike*)entity, position);


    if (typeid (carapace).name() == typeid(*entity).name()) collisionSpec((carapace*)entity, position);
    if (typeid (bowser).name() == typeid(*entity).name()) collisionSpec((bowser*)entity, position);
    if (typeid (bowser_fire).name() == typeid(*entity).name()) collisionSpec((bowser_fire*)entity, position);
    }

    if (typeid (GoalPole).name() == typeid(*entity).name()) collisionSpec((GoalPole*)entity, position);
    if (typeid (mushroom).name() == typeid(*entity).name()) collisionSpec((mushroom*)entity, position);
    if (typeid (billblaster).name() == typeid(*entity).name()) collisionSpec((billblaster*)entity, position);
    if (typeid (Tuyau).name() == typeid(*entity).name()) collisionSpec((Tuyau*)entity, position);
    if (typeid (lifeup).name() == typeid(*entity).name()) collisionSpec((lifeup*)entity, position);
    if (typeid (star).name() == typeid(*entity).name()) collisionSpec((star*)entity, position);
    if (typeid (flower).name() == typeid(*entity).name()) collisionSpec((flower*)entity, position);
    if (typeid (mysteryblock).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (Block).name() == typeid(*entity).name()) collisionSpec((Block*)entity, position);
    if (typeid (BlockGrass).name() == typeid(*entity).name()) collisionSpec((BlockGrass*)entity, position);
    if (typeid (CheckPoint).name() == typeid(*entity).name()) collisionSpec((CheckPoint*)entity, position);
    if (typeid (Piece).name() == typeid(*entity).name()) collisionSpec((Piece*)entity, position);
    if (typeid (Chateau).name() == typeid(*entity).name()) collisionSpec((Chateau*)entity, position);
    if (typeid (Trampoline).name() == typeid(*entity).name()) collisionSpec((Trampoline*)entity, position);


}

void Mario::update()
{
    if(background_sound->state() == QMediaPlayer::StoppedState && !goal)background_sound->play();
    if(!mort && !goal){

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
               mort = true;

            }


        }

        if(input->up && cptjump ==0 && !move_to_down){
            jump = true;
            if(jump_sound->state() != QMediaPlayer::PlayingState)jump_sound->play();
        }

        if(jump){

            if(move_to_up){
               state = 3;
               if(input->right )state = 3;
               if(input->left )state = 5;
               this->move_to_down = false;
               coord_y-=5;
               if(contact_trampoline)coord_y-=5;
               cptjump++;
               if(cptjump <= 2){
                   setOn_ground(false);
               }
               if(cptjump == 30){
                   jump = false;
                   contact_trampoline = false;
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

        if(!grand) {
            if(state == 0)state = 8;
            if(state == 1)state = 9;
            if(state == 3)state = 11;
            if(state == 4)state = 12;
            if(state == 5)state = 13;

            if(cptPetit<=80){
                if(cptClign>10)state = 10;
                cptClign++;
                if(cptClign>20)cptClign=0;
                cptPetit++;
            }


        }

        if(invincible){
            if(getCptinvincible()<666){
                state = 7;
                setCptinvincible(getCptinvincible()+1);
            }
            if(getCptinvincible()==666){
                setInvincible(false);
                background_sound->setMuted(false);
                star_sound->stop();
            }
        }



    }
    else if(mort){
        if(grand){
            grand = false;
            mort = false;
            cptPetit=0;
        }
        else{
            star_sound->stop();
            background_sound->stop();
            if(level->getNbVie()<=0){
                game_over_sound->play();
            }
            else{
                mario_die_sound->play();
            }

            state = 6;
            if (cptmort >=120 )   coord_y+=5;

            if(coord_y>800){
               state_dead = true;


            }
            cptmort ++;

        }



    }
    else if(goal){
        if (cptEnd == 0)  {

            star_sound->stop();
            background_sound->stop();
            if(victory_sound->state() != QMediaPlayer::PlayingState)victory_sound->play();
            coord_x+=30;

            state = 5;
        }
        else{
            if (coord_y<625) coord_y+=1;
            else{
                if(state != 1)refresh = true;
                state = 1;
                 if(cptEnd < 10100)coord_x+=1;
                 else if(cptEnd == 10100)level->setFin_level(true);
            }

        }
        cptEnd++;

    }
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

void Mario::collisionSpec(BlockGrass *entity, int position)
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

    if(cptEnd<10000)cptEnd = 10000;
     if(cptEnd==10070) entity->setRefresh(true);
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


    switch (position) {
        case 0 :
            break;
        case 1:
            this->move_to_right = false;
            break;
        case 2:
            move_to_down = false;
            setContact_trampoline(true);
            jump= true;
            cptjump=5;
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
            if(!getInvincible())mort = true;

            break;
        case 1:
        if(!getInvincible())mort = true;

            this->move_to_right = false;
            break;
        case 2:
        jump= true;
        cptjump=0;
        break;
        case 3:
            if(!getInvincible()) mort = true;
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(bowser *entity, int position)
{
    move_to_down = false;
    switch (position) {
        case 0 :
            if(!getInvincible())mort = true;

            break;
        case 1:
        if(!getInvincible())mort = true;

            this->move_to_right = false;
            break;
        case 2:
        jump= true;
        cptjump=0;
        break;
        case 3:
            if(!getInvincible()) mort = true;
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(bulletbill *entity, int position)
{
    switch (position) {
        case 0 :
            if(!getInvincible()) mort = true;
            break;
        case 1:
            if(!getInvincible())mort = true;
            this->move_to_right = false;
            break;
        case 2:
            jump= true;
            cptjump=0;
            break;
        case 3:
            if(!getInvincible()) mort = true;
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(Koopa *entity, int position)
{
    move_to_down = false;
    switch (position) {
        case 0 :
            if(!getInvincible()) mort = true;
            break;
        case 1:
            if(!getInvincible()) mort = true;
            this->move_to_right = false;
            break;
        case 2:
            jump= true;
            cptjump=0;
            break;
        case 3:
            if(!getInvincible()) mort = true;
            this->move_to_left = false;
            break;
    }
}

void Mario::collisionSpec(carapace *entity, int position)
{
    move_to_down = false;
    if(entity->getState()==1 && entity->getCompteur() > 20){
        switch (position) {
            case 0 :
                if(!getInvincible()) mort = true;
                break;
            case 1:
                if(!getInvincible())mort = true;
                this->move_to_right = false;
                break;
            case 2:
                jump= true;
                cptjump=0;
                break;
            case 3:
                if(!getInvincible()) mort = true;
                this->move_to_left = false;
                break;
        }
    }
}

void Mario::collisionSpec(CheckPoint *entity, int position)
{
    level->setCoord_x_cp(entity->getCoordX());
    level->setCoord_y_cp(entity->getCoordY()-3);
    level->setScore_cp(level->getScore());


}

void Mario::collisionSpec(GoalPole *entity, int position)
{
    goal = true;

}

void Mario::collisionSpec(plante *entity, int position)
{
    if(!getInvincible()) mort = true;
}

void Mario::collisionSpec(flamme *entity, int position)
{
    if(!getInvincible()) mort = true;
}

void Mario::collisionSpec(spike *entity, int position)
{
    if(!getInvincible()) mort = true;
}

void Mario::collisionSpec(bowser_fire *entity, int position)
{
    if(!getInvincible()) mort = true;
}

void Mario::collisionSpec(thwomp *entity, int position)
{
    setContact_thwomp(true);
    switch (position) {
        case 0 :
            if(getOn_ground() && getContact_thwomp() && !entity->getMove_to_up()) mort = true;
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
    if(coin_sound->state() == QMediaPlayer::PlayingState)coin_sound->setPosition(0);
    if(coin_sound->state() == QMediaPlayer::StoppedState)coin_sound->play();

}

void Mario::collisionSpec(mushroom *entity, int position)
{
    if(powerup_sound->state() == QMediaPlayer::PlayingState)powerup_sound->setPosition(0);
    if(powerup_sound->state() == QMediaPlayer::StoppedState)powerup_sound->play();
    if(!grand){
        grand = true;
        coord_y-=10;
    }
}

void Mario::collisionSpec(lifeup *entity, int position)
{
    if(lifeup_sound->state() == QMediaPlayer::PlayingState)lifeup_sound->setPosition(0);
    if(lifeup_sound->state() == QMediaPlayer::StoppedState)lifeup_sound->play();
    level->SetNbVie(level->getNbVie()+1);
}

void Mario::collisionSpec(star *entity, int position)
{
    setInvincible(true);
    if(star_sound->state() == QMediaPlayer::PlayingState)star_sound->setPosition(0);
    if(star_sound->state() == QMediaPlayer::StoppedState)star_sound->play();
    background_sound->setMuted(true);
    setCptinvincible(0);
}

void Mario::collisionSpec(flower *entity, int position)
{
    if(powerup_sound->state() == QMediaPlayer::PlayingState)powerup_sound->setPosition(0);
    if(powerup_sound->state() == QMediaPlayer::StoppedState)powerup_sound->play();
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

bool Mario::getContact_trampoline() const
{
    return contact_trampoline;
}

void Mario::setContact_trampoline(bool value)
{
    contact_trampoline = value;
}

bool Mario::getInvincible() const
{
    return invincible;
}

void Mario::setInvincible(bool value)
{
    invincible = value;
}

int Mario::getCptinvincible() const
{
    return cptinvincible;
}

void Mario::setCptinvincible(int value)
{
    cptinvincible = value;
}
