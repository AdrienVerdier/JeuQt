#include "game_view.h"
#include <QDebug>

Game_View::Game_View(QWidget *parent)
{
    setSceneRect(0,0,1280,720);


}

void Game_View::paint(Entity *entity){
    if(entity->getDisplay()){
        if (map_Entity_GameViewEntity.contains(entity))
            map_Entity_GameViewEntity[entity]->update_Img(entity->getCoordX(),entity->getCoordY(),entity->getState());
        else{
           map_Entity_GameViewEntity[entity] = entity_factory.create(entity);
           this->addItem(map_Entity_GameViewEntity[entity]);
        }
    }
    else{
        if (map_Entity_GameViewEntity.contains(entity)){
            this->removeItem(map_Entity_GameViewEntity[entity]);
            delete map_Entity_GameViewEntity[entity];
            map_Entity_GameViewEntity.remove(entity);
        }

    }
}
