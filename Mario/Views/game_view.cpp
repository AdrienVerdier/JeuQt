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

QMap<Entity*, QMap<Entity*,int>> Game_View::get_list_collides()
{



    QMap<Entity*,  QMap<Entity*,int>> list_collides;
    foreach(Entity *entity, map_Entity_GameViewEntity.keys())
    {
        foreach(Entity *collideswith, map_Entity_GameViewEntity.keys())
        {
            if(entity != collideswith &&  entity->getCollision() && collideswith->getCollision())
            {
                if(map_Entity_GameViewEntity[entity]->collidesWithItem( map_Entity_GameViewEntity[collideswith])){
                    fillPoints(map_Entity_GameViewEntity[entity],map_Entity_GameViewEntity[collideswith]);
                    if(E1["Haut"] < E2["Bas"] && E1["Haut"] > E2["Haut"]){
                        if(E2["Bas"]-E1["Haut"]<=10) list_collides[entity][collideswith] = 0; //Collision TOP
                        else if(E1["Droite"]>E2["Gauche"] && E1["Droite"]<E2["Droite"])list_collides[entity][collideswith] = 1; //Collision RIGHT
                        else list_collides[entity][collideswith] = 3; //Collision LEFT
                    }
                    if(E1["Bas"] > E2["Haut"] && E1["Bas"] > E2["Bas"]){
                        if(E1["Bas"]-E2["Haut"]<=10) list_collides[entity][collideswith] = 2; //Collision BOTTOM
                        else if(E1["Droite"]>E2["Gauche"] && E1["Droite"]<E2["Droite"])list_collides[entity][collideswith] = 1; //Collision RIGHT
                        else list_collides[entity][collideswith] = 3; //Collision LEFT
                    }

                }

            }

        }
    }
    return list_collides;
}


void Game_View::fillPoints(Game_View_Entity *e1, Game_View_Entity *e2)
{
    E1["Haut"]= e1->y();
    E1["Bas"] = e1->y()+e1->boundingRect().height();
    E1["Gauche"] = e1->x();
    E1["Droite"] = e1->x()+e1->boundingRect().width();

    E2["Haut"]= e2->y();
    E2["Bas"] = e2->y()+e2->boundingRect().height();
    E2["Gauche"] = e2->x();
    E2["Droite"] = e2->x()+e2->boundingRect().width();

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


