#include "game_view_factory.h"
#include<QDebug>
#include <typeinfo>  //for 'typeid' to work


Game_View_Factory::Game_View_Factory()
{

}

Game_View_Entity *Game_View_Factory::create(Entity *e,int x)
{

    if (typeid (Mario).name() == typeid(*e).name()) return create((Mario*)e,x);
    if (typeid (Block).name() == typeid(*e).name()) return create((Block*)e, x);
    if (typeid (Goomba).name() == typeid(*e).name()) return create((Goomba*)e, x);
    if (typeid (Koopa).name() == typeid(*e).name()) return create((Koopa*)e, x);
}


Game_View_Entity* Game_View_Factory::create(Mario *m,int x){


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

          Game_View_Entity *entity_view = new Game_View_Entity(map,x,m->getCoordY(),m->getState());

          return entity_view;

}


Game_View_Entity* Game_View_Factory::create(Block *b, int x){


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


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,b->getCoordY(),b->getState());

          return entity_view;

}

Game_View_Entity *Game_View_Factory::create(Goomba *g,int x)
{
        QMap<int,QList<QString>> map;

        QString val;
        QFile file;
        file.setFileName(":images/images/Characters_Animations_Pattern.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("goomba"));

        QJsonObject goomba = value.toObject();

        map[0].push_back(goomba["0"].toArray()[0].toString());


        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(Koopa *g,int x)
{
        QMap<int,QList<QString>> map;

        QString val;
        QFile file;
        file.setFileName(":images/images/Characters_Animations_Pattern.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();
        QJsonValue value = sett2.value(QString("koopa"));

        QJsonObject koopa = value.toObject();
        for(int i =0;i<5;i++)
        map[0].push_back(koopa["0"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}
