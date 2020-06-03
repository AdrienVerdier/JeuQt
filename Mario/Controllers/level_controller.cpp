#include "level_controller.h"
#include "../Views/game_view.h"
#include <QTimer>
#include <QObject>
#include<QDebug>
#include <QElapsedTimer>


Level_Controller::Level_Controller()
{

    game_view = new Game_View();
    reset = false;
    // Init Level
    level = new Level();
    level->getPlayer()->setInputs(game_view->get_Keys());


    m_timer = new QTimer(this);
    QObject::connect(m_timer,SIGNAL(timeout()),this,SLOT(update_lvl()));
    m_timer->start(15);

}

Game_View *Level_Controller::getScene()
{
    return game_view;
}

void Level_Controller::select_display_element()
{

    int pos_centre = level->getPlayer()->getCoordX();
    if(pos_centre<640)pos_centre=640;
    current_entity_list.clear();


    current_entity_list.push_back(level->getPlayer());



    foreach(Entity* entity,*level->get_alive_entity_list()){
        float distance = entity->getDistanceOn_X(pos_centre);
        if(distance < 650 && distance > -650){

            if(!entity->getDead()){
                entity->setDisplay(true);
                current_entity_list.push_back(entity);
            }
            else if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
            }
            else{
                level->get_alive_entity_list()->removeOne(entity);
                //delete entity;
            }

        }
        else
        {
           if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
           }
           else if(entity->getDead()){
               level->get_alive_entity_list()->removeOne(entity);
              // delete entity;
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
            else{
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
            }

        }
        else
        {
           if(entity->getDisplay()){
                entity->setDisplay(false);
                current_entity_list.push_back(entity);
           }
        }
    }





}

void Level_Controller::update_view()
{
    game_view->setMx(level->getPlayer()->getCoordX());
    select_display_element();
    foreach(Entity *entity, current_entity_list){
       // game_view->paint(entity);
        entity->accept(game_view);
    }


}

void Level_Controller::update_lvl()
{
    QElapsedTimer timer;
      timer.start();
    if(level->getPlayer()->getDead()){
        delete level;
        level = new Level();
        level->getPlayer()->setInputs(game_view->get_Keys());
        game_view->reset();
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


    /*\ Pour le moment on update l'ensemble des objets du niveau, par la suite il faudra mettre current_entity_list à jour selon les coordonnées de Mario et les objets morts ou nouveaux) \*/



}
