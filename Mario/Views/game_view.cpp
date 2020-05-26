#include "game_view.h"
#include <QKeyEvent>


Game_View::Game_View(QWidget *parent)
{
    setSceneRect(0,0,1280,720);
    controls = new Controls();


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

QMap<Entity*, QList<Entity*>> Game_View::get_list_collides()
{
    QMap<Entity*, QList<Entity*>> list_collides;
    foreach(Entity *entity, map_Entity_GameViewEntity.keys())
    {
        foreach(Entity *collideswith, map_Entity_GameViewEntity.keys())
        {
            if(entity != collideswith)
            {
                if(map_Entity_GameViewEntity[entity]->collidesWithItem( map_Entity_GameViewEntity[collideswith]))
                    list_collides[entity].push_back(collideswith);
            }

        }
    }
    return list_collides;
}

void Game_View::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key()== Qt::Key_Up && !keyEvent->isAutoRepeat())
    {
       controls->up = true;
    }
    if(keyEvent->key()== Qt::Key_Right && !keyEvent->isAutoRepeat())
    {
       controls->right = true;
    }
    if(keyEvent->key()== Qt::Key_Down && !keyEvent->isAutoRepeat())
    {
       controls->down = true;
    }
    if(keyEvent->key()== Qt::Key_Left && !keyEvent->isAutoRepeat())
    {
       controls->left = true;
    }
    if(keyEvent->key()== Qt::Key_Space && !keyEvent->isAutoRepeat())
    {
       controls->up = true;
    }
}


void Game_View::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key()== Qt::Key_Up && !keyEvent->isAutoRepeat())
    {
       controls->up = false;
    }
    if(keyEvent->key()== Qt::Key_Right && !keyEvent->isAutoRepeat())
    {
       controls->right = false;
    }
    if(keyEvent->key()== Qt::Key_Down && !keyEvent->isAutoRepeat())
    {
       controls->down = false;
    }
    if(keyEvent->key()== Qt::Key_Left && !keyEvent->isAutoRepeat())
    {
       controls->left = false;
    }
    if(keyEvent->key()== Qt::Key_Space && !keyEvent->isAutoRepeat())
    {
       controls->up = false;
    }
}

Controls *Game_View::get_Keys()
{
    return controls;
}
