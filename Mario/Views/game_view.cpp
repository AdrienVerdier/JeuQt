#include "game_view.h"
#include <QKeyEvent>
#include "../Models/mario.h"
#include "../Models/goomba.h"
#include "../Models/piece.h"
#include "../Models/lifeup.h"
#include "../Models/star.h"
#include "../Models/mushroom.h"
#include "../Models/flower.h"

#include<QDebug>
#include <QRectF>


Game_View::Game_View(QWidget *parent)
{
    setSceneRect(0,0,1280,700);
    controls = new Controls();
    this->setBackgroundBrush(QBrush(Qt::cyan, Qt::SolidPattern));
    QFont f( "Arial", 20, QFont::Bold);

    //HUD
    score = new QLabel();
    score->setText("10");
    score->setGeometry(QRect(50, 10,30, 30));
    score->setFont(f);
    score->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(score);

    pieceHUD = new QGraphicsPixmapItem(QPixmap(":images/images/HUD/pieceHUD.png"));
    this->addItem(pieceHUD);
    pieceHUD->setPos(15, 10);


    vies = new QLabel();
    vies->setText("3");
    vies->setGeometry(QRect(1230, 10,30, 30));
    vies->setFont(f);
    vies->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(vies);

    viesHUD = new QGraphicsPixmapItem(QPixmap(":images/images/HUD/viesHUD.png"));
    this->addItem(viesHUD);
    viesHUD->setPos(1195, 10);


    QPixmap bk(":images/images/HUD/background.png");

    background = new QGraphicsPixmapItem(bk.scaled(QSize(1280,720)));
    this->addItem(background);
    background->setPos(0, 0);

    xLeftLimit = 640;



}

void Game_View::reset(){

    foreach(Entity *entity, map_Entity_GameViewEntity.keys()){
        this->removeItem(map_Entity_GameViewEntity[entity]);
        delete map_Entity_GameViewEntity[entity];
        map_Entity_GameViewEntity.remove(entity);
        xLeftLimit = 640;
    }
}

void Game_View::paint(Entity *entity){

    if(Mx>=xLeftLimit) {
        x = entity->getCoordX()-(Mx-640);
        xLeftLimit = Mx;
    }
    else{
        x = entity->getCoordX()-(xLeftLimit-640);



    }
    if(entity->getDisplay()){
        if (map_Entity_GameViewEntity.contains(entity)){
          map_Entity_GameViewEntity[entity]->update_Img(x,entity->getCoordY(),entity->getState());
        }
        else{
           map_Entity_GameViewEntity[entity] = entity_factory.create(entity,x);
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

QMap<Entity*, QMap<Entity*,int>> Game_View::get_list_collides( )
{
    QList<Entity*> listeTestCol;
    foreach(Entity *entity,map_Entity_GameViewEntity.keys()){
        if(entity->getMove()) listeTestCol.push_back(entity);
    }



    QMap<Entity*,  QMap<Entity*,int>> list_collides;
    foreach(Entity *entity, listeTestCol)
    {
        foreach(Entity *collideswith, map_Entity_GameViewEntity.keys())
        {
            if(entity != collideswith &&  entity->getCollision() && collideswith->getCollision())
            {

                if(map_Entity_GameViewEntity[entity]->collidesWithItem( map_Entity_GameViewEntity[collideswith])){

                    if (typeid (Mario).name() == typeid(*entity).name()){

                        QRectF rectHaut(map_Entity_GameViewEntity[entity]->x()+10,map_Entity_GameViewEntity[entity]->y(),map_Entity_GameViewEntity[entity]->boundingRect().width()-20,10);
                        QRectF rectBas(map_Entity_GameViewEntity[entity]->x()+10,map_Entity_GameViewEntity[entity]->y()+map_Entity_GameViewEntity[entity]->boundingRect().height()-10,map_Entity_GameViewEntity[entity]->boundingRect().width()-20,10);
                         QRectF rectGauche(map_Entity_GameViewEntity[entity]->x(),map_Entity_GameViewEntity[entity]->y()+10,10,map_Entity_GameViewEntity[entity]->boundingRect().height()-20);
                         QRectF rectDroite(map_Entity_GameViewEntity[entity]->x()+map_Entity_GameViewEntity[entity]->boundingRect().width()-10,map_Entity_GameViewEntity[entity]->y()+10,10,map_Entity_GameViewEntity[entity]->boundingRect().height()-20);

                        QRectF rect(map_Entity_GameViewEntity[collideswith]->x(),map_Entity_GameViewEntity[collideswith]->y(),map_Entity_GameViewEntity[collideswith]->boundingRect().width(),map_Entity_GameViewEntity[collideswith]->boundingRect().height());

                         if(rectHaut.intersects(rect)){
                              qInfo() << "coucou";
                             list_collides[entity][collideswith] = 0;
                             list_collides[collideswith][entity] = 2;
                         }
                         if(rectBas.intersects(rect)) {
                             list_collides[entity][collideswith] = 2;
                             list_collides[collideswith][entity] = 0;
                         }
                          if(rectGauche.intersects(rect)) {
                              list_collides[entity][collideswith] = 3;
                              list_collides[collideswith][entity] = 1;
                          }
                           if(rectDroite.intersects(rect)) {
                               list_collides[entity][collideswith] = 1;
                               list_collides[collideswith][entity] = 3;
                           }
                    }
                    else if(typeid (Mario).name() == typeid(*collideswith).name()){

                    }
                    else{
                        fillPoints(map_Entity_GameViewEntity[entity],map_Entity_GameViewEntity[collideswith]);

                        if(E1["Haut"] <= E2["Bas"] && E1["Haut"] > E2["Haut"]){
                              if( E2["Bas"] - E1["Haut"] <=5)list_collides[entity][collideswith] = 0; //Collision TOP
                            else if(E1["Droite"]>=E2["Gauche"] && E1["Droite"]<E2["Droite"]){
                                 if(E1["Droite"]-E2["Gauche"]<=5)list_collides[entity][collideswith] = 1; //Collision RIGHT
                            }
                            else if(E1["Gauche"]<=E2["Droite"] && E1["Gauche"]>E2["Gauche"]){
                                 if(E2["Droite"] -E1["Gauche"]<=5)list_collides[entity][collideswith] = 3; //Collision LEFT

                            }

                        }
                        else if(E1["Bas"] >= E2["Haut"] && E1["Bas"] < E2["Bas"]){
                             if(E1["Bas"] - E2["Haut"]<=5)list_collides[entity][collideswith] = 2; //Collision TOP
                             else if(E1["Droite"]>=E2["Gauche"] && E1["Droite"]<E2["Droite"]){

                               if(E1["Droite"]-E2["Gauche"]<=5)list_collides[entity][collideswith] = 1; //Collision RIGHT
                            }
                             else if(E1["Gauche"]<=E2["Droite"] && E1["Gauche"]>E2["Gauche"]){

                                if(E2["Droite"] -E1["Gauche"]<=5)list_collides[entity][collideswith] = 3; //Collision LEFT
                            }

                        }
                        else{
                            if(E1["Droite"]>=E2["Gauche"] && E1["Droite"]<E2["Droite"])list_collides[entity][collideswith] = 1; //Collision RIGHT
                            else if(E1["Gauche"]<=E2["Droite"] && E1["Gauche"]>E2["Gauche"]){

                                list_collides[entity][collideswith] = 3; //Collision LEFT
                            }
                        }
                    }

                }

            }

        }
    }
    return list_collides;
}


void Game_View::fillPoints(Game_View_Entity *e1, Game_View_Entity *e2)
{
    E1.clear();
    E2.clear();
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


void Game_View::setMx(int value)
{
    Mx = value;
}

int Game_View::getXLeftLimit() const
{
    return xLeftLimit;
}

void Game_View::setXLeftLimit(int value)
{
    xLeftLimit = value;
}


