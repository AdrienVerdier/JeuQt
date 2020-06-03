#include "level.h"
#include "mario.h"
#include "block.h"
#include <QImage>
#include<QDebug>

#include <typeinfo>
#include <QDebug>
Level::Level()
{
    score = 0;
    nbVie = 3;

    entity_list = new QList<Entity*>();
    alive_entity_list = new QList<Entity*>();

    /*\     AJOUTS TEMPORAIRES    \*/

    Mario * m = new Mario();
    m->setDisplay(true);
    m->setCoordX(0);
    m->setCoordY(2);
    m->setState(1);
    player = m;

    QImage level_img;
    level_img.load(":images/images/Niveau/Niv1.png");


    for ( int row = 10; row < level_img.height(); row+=25 )
        for ( int col = 10; col < level_img.width(); col+=25 )
        {
            QColor clrCurrent( level_img.pixel( col, row ) );
            if(clrCurrent.red() == 185 && clrCurrent.green()==122 &&clrCurrent.blue()==87){
                entity_list->push_back(new Block());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 0 && clrCurrent.green()==162 &&clrCurrent.blue()==232){
                entity_list->push_back(new Tuyau());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);
            }
            if(clrCurrent.red() == 239 && clrCurrent.green()==228 &&clrCurrent.blue()==176){
                entity_list->push_back(new mysteryblock());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 112 && clrCurrent.green()==146 &&clrCurrent.blue()==190){
                entity_list->push_back(new Chateau());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 136 && clrCurrent.green()== 0 &&clrCurrent.blue()== 21){
                entity_list->push_back(new Trampoline());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 0 && clrCurrent.green()== 0 &&clrCurrent.blue()== 255){
                entity_list->push_back(new spike());
                entity_list->last()->setDisplay(true);
                entity_list->last()->setCoordX(col-10);
                entity_list->last()->setCoordY(row-10);
                entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 255 && clrCurrent.green()==201 &&clrCurrent.blue()==14){
                alive_entity_list->push_back(new Goomba());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 255 && clrCurrent.green()==242 &&clrCurrent.blue()==0){
                alive_entity_list->push_back(new Piece());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-10);
                alive_entity_list->last()->setState(0);
            }
            if(clrCurrent.red() == 34 && clrCurrent.green()==177 &&clrCurrent.blue()==76){
                alive_entity_list->push_back(new Koopa());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 237 && clrCurrent.green()==28 &&clrCurrent.blue()==36){
                alive_entity_list->push_back(new plante());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 255 && clrCurrent.green()==127 &&clrCurrent.blue()==39){
                alive_entity_list->push_back(new flamme());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 195 && clrCurrent.green()==195 &&clrCurrent.blue()==195){
                alive_entity_list->push_back(new thwomp());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 181 && clrCurrent.green()==230 &&clrCurrent.blue()==29){
                alive_entity_list->push_back(new bulletbill(true));
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 163 && clrCurrent.green()==73 &&clrCurrent.blue()==164){
                alive_entity_list->push_back(new bulletbill(false));
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 63 && clrCurrent.green()==72 &&clrCurrent.blue()==204){
                alive_entity_list->push_back(new billblaster());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 255 && clrCurrent.green()==174 &&clrCurrent.blue()==201){
                alive_entity_list->push_back(new smoke());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 255 && clrCurrent.green()==255 &&clrCurrent.blue()==0){
                alive_entity_list->push_back(new star());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 255 && clrCurrent.green()==128 &&clrCurrent.blue()==0){
                alive_entity_list->push_back(new flower());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 255 && clrCurrent.green()==0 &&clrCurrent.blue()==0){
                alive_entity_list->push_back(new mushroom());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }

            if(clrCurrent.red() == 0 && clrCurrent.green()==255 &&clrCurrent.blue()==0){
                alive_entity_list->push_back(new lifeup());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
        }
}

QList<Entity *> *Level::get_entity_list()
{
    return entity_list;
}

QList<Entity *> *Level::get_alive_entity_list()
{
    return alive_entity_list;
}

Mario *Level::getPlayer()
{
  return player;
}
