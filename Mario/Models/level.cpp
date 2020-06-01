#include "level.h"
#include "mario.h"
#include "block.h"
#include <QImage>
#include<QDebug>

Level::Level()
{

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
            if(clrCurrent.red() == 255 && clrCurrent.green()==201 &&clrCurrent.blue()==14){
                alive_entity_list->push_back(new Goomba());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-14);
                alive_entity_list->last()->setState(0);

            }
            if(clrCurrent.red() == 255 && clrCurrent.green()==242 &&clrCurrent.blue()==0){
                qInfo() << "New Piece" ;
                alive_entity_list->push_back(new Piece());
                alive_entity_list->last()->setDisplay(true);
                alive_entity_list->last()->setCoordX(col-10);
                alive_entity_list->last()->setCoordY(row-10);
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
