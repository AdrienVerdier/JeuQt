#include "level_controller.h"
#include "../Views/game_view.h"
#include <QTimer>
#include <QObject>
#include<QDebug>
#include <QElapsedTimer>
#include "../Models/static_entity.h"
#include "global_views_controller.h"


Level_Controller::Level_Controller( Global_Views_Controller *p)
{

    game_view = new Game_View();
    reset = false;

    pere = p;

    m_timer = new QTimer(this);
    QObject::connect(m_timer,SIGNAL(timeout()),this,SLOT(update_lvl()));
    m_timer->start(15);
    pause = true;


    background_sound = new QMediaPlayer();
    background_sound->setMedia(QUrl("qrc:/son/son/background.mp3"));
    background_sound->setVolume(10);
    mario_die_sound = new QMediaPlayer();
    mario_die_sound->setMedia(QUrl("qrc:/son/son/mario_die.mp3"));
    mario_die_sound->setVolume(30);
    game_over_sound = new QMediaPlayer();
    game_over_sound->setMedia(QUrl("qrc:/son/son/game_over.mp3"));
    game_over_sound->setVolume(30);

}

Game_View *Level_Controller::getScene()
{
    return game_view;
}

void Level_Controller::select_display_element()
{

    int pos_centre = game_view->getXLeftLimit();

    current_entity_list.clear();


    current_entity_list.push_back(level->getPlayer());



    foreach(Alive_Entity* entity,*level->get_alive_entity_list()){
        float distance = entity->getDistanceOn_X(pos_centre);
        if(distance < 650 && distance > -650){

            if(!entity->getDead()){

                     current_entity_list.push_back(entity);
                        entity->setDisplay(true);

            }
            else if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
            }
            else{
                level->get_alive_entity_list()->removeOne(entity);
                delete entity;
            }

        }
        else if(distance<=650)
        {
           if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
           }
           else if(entity->getDead()){
               level->get_alive_entity_list()->removeOne(entity);
               delete entity;
           }
        }
        else{
            if(entity->getDisplay()){
                 entity->setDisplay(false);
                 current_entity_list.push_back(entity);
            }
            else{
                 level->get_alive_entity_list()->removeOne(entity);
                 delete entity;
            }
        }
    }
    foreach(Entity* entity,*level->get_entity_list()){
        float distance = entity->getDistanceOn_X(pos_centre);
        if(distance < 700 && distance > -700){

            if(!entity->getDead()){
                entity->setDisplay(true);
                current_entity_list.push_back(entity);
            }
            else if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
            }
            else{
                level->get_entity_list()->removeOne(entity);
                delete entity;
            }

        }
        else if(distance<=700)
        {
           if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
           }
           else if(entity->getDead()){
               level->get_entity_list()->removeOne(entity);
               delete entity;
           }
        }
        else{
            if(entity->getDisplay()){
                 entity->setDisplay(false);
                 current_entity_list.push_back(entity);
            }
            else{
                 level->get_entity_list()->removeOne(entity);
                 delete entity;
            }
        }
    }





}

void Level_Controller::update_view()
{
    game_view->setMx(level->getPlayer()->getCoordX());
    select_display_element();
    game_view->update_HUD(level->getScore(), level->getNbVie());
    foreach(Entity *entity, current_entity_list){
       // game_view->paint(entity);
        entity->accept(game_view);
    }


}

void Level_Controller::NewLevel(QString path){

    level = new Level();
     game_view->reset();
    level->getPlayer()->setInputs(game_view->get_Keys());
    pause = false;
    path_level_en_cours = path;

}

void Level_Controller::update_lvl()
{
    if(! pause){
        if(background_sound->state() == QMediaPlayer::StoppedState)background_sound->play();
        QElapsedTimer timer;
          timer.start();
        if(level->getPlayer()->getDead()){
            background_sound->stop();
            if(level->getNbVie()<=0){
                pause = true;
                pere->display_GameOver();
                game_over_sound->play();
            }
            else{
                int vies = level->getNbVie()-1;
                NewLevel(path_level_en_cours);
                level->SetNbVie(vies);
                mario_die_sound->play();
            }
        }

        update_view();

        collision_List =  game_view->get_list_collides();
        foreach(Entity *entity, collision_List.keys())
        {
            foreach(Entity *collideswith, collision_List[entity].keys())
            {
                    if(entity->getDisplay())entity->collision(collideswith,collision_List[entity][collideswith]);
            }
        }
        foreach(Entity *entity,current_entity_list){
             if(entity->getDisplay())entity->update();
        }

        qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";
    }




}
