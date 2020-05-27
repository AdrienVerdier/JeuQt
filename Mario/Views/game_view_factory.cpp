#include "game_view_factory.h"
#include<QDebug>
#include <typeinfo>  //for 'typeid' to work


Game_View_Factory::Game_View_Factory()
{

}

Game_View_Entity *Game_View_Factory::create(Entity *e)
{

    if (typeid (Mario).name() == typeid(*e).name()) return create((Mario*)e);
    if (typeid (Block).name() == typeid(*e).name()) return create((Block*)e);
}


Game_View_Entity* Game_View_Factory::create(Mario *m){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("mario"));

          QJsonObject mario = value.toObject();

          map[0].push_back(mario["0"].toArray()[0].toString());
          for(int i =0;i<6;i++)
            map[1].push_back(mario["1"].toArray()[i].toString());
          map[2].push_back(mario["2"].toArray()[0].toString());
          map[3].push_back(mario["3"].toArray()[0].toString());

          Game_View_Entity *entity_view = new Game_View_Entity(map,m->getCoordX(),m->getCoordY(),m->getState());

          return entity_view;

}


Game_View_Entity* Game_View_Factory::create(Block *b){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("block"));

          QJsonObject block = value.toObject();

          map[0].push_back(block["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,b->getCoordX(),b->getCoordY(),b->getState());

          return entity_view;

}
