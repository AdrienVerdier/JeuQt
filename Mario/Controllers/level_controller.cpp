#include "level_controller.h"
#include "../Views/game_view.h"
#include <QTimer>
#include <QObject>

Level_Controller::Level_Controller()
{

    game_view = new Game_View();

    // Init Level
    level = new Level();

    //Init current List (temporaire)
    foreach(Entity *entity, *level->get_entity_list()){
        current_entity_list.push_back(entity);
    }


    m_timer = new QTimer(this);
    QObject::connect(m_timer,SIGNAL(timeout()),this,SLOT(update_lvl()));
    m_timer->start(80);

}

Game_View *Level_Controller::getScene()
{
    return game_view;
}

void Level_Controller::update_view()
{
    foreach(Entity *entity, current_entity_list){
        game_view->paint(entity);
    }

}

void Level_Controller::update_lvl()
{
    update_view();
}
