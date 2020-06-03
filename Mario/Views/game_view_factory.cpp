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
    if (typeid (Piece).name() == typeid(*e).name()) return create((Piece*)e, x);
    if (typeid (Koopa).name() == typeid(*e).name()) return create((Koopa*)e, x);
    if (typeid (plante).name() == typeid(*e).name()) return create((plante*)e, x);
    if (typeid (flamme).name() == typeid(*e).name()) return create((flamme*)e, x);
    if (typeid (thwomp).name() == typeid(*e).name()) return create((thwomp*)e, x);
    if (typeid (bulletbill).name() == typeid(*e).name()) return create((bulletbill*)e, x);
    if (typeid (billblaster).name() == typeid(*e).name()) return create((billblaster*)e, x);
    if (typeid (smoke).name() == typeid(*e).name()) return create((smoke*)e, x);
    if (typeid (Tuyau).name() == typeid(*e).name()) return create((Tuyau*)e, x);
    if (typeid (mysteryblock).name() == typeid(*e).name()) return create((mysteryblock*)e, x);
    if (typeid (lifeup).name() == typeid(*e).name()) return create((lifeup*)e, x);
    if (typeid (mushroom).name() == typeid(*e).name()) return create((mushroom*)e, x);
    if (typeid (star).name() == typeid(*e).name()) return create((star*)e, x);
    if (typeid (flower).name() == typeid(*e).name()) return create((flower*)e, x);
    if (typeid (Chateau).name() == typeid(*e).name()) return create((Chateau*)e, x);
    if (typeid (Trampoline).name() == typeid(*e).name()) return create((Trampoline*)e, x);
    if (typeid (spike).name() == typeid(*e).name()) return create((spike*)e, x);
    if (typeid (carapace).name() == typeid(*e).name()) return create((carapace*)e, x);
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
          for(int i =0;i<6;i++)
          map[4].push_back(mario["4"].toArray()[i].toString());
          map[5].push_back(mario["5"].toArray()[0].toString());

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

Game_View_Entity* Game_View_Factory::create(Trampoline *t, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("trampoline"));

          QJsonObject trampoline = value.toObject();

          map[0].push_back(trampoline["0"].toArray()[0].toString());
          for(int i =0;i<5;i++)
          map[1].push_back(trampoline["1"].toArray()[i].toString());

          Game_View_Entity *entity_view = new Game_View_Entity(map,x,t->getCoordY(),t->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(Tuyau *t, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("tuyau"));

          QJsonObject tuyau = value.toObject();

          map[0].push_back(tuyau["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,t->getCoordY(),t->getState());

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
        for(int i =0;i<7;i++)
        map[0].push_back(goomba["0"].toArray()[i].toString());
        for(int i =0;i<7;i++)
        map[1].push_back(goomba["1"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(Piece *p,int x)
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
        QJsonValue value = sett2.value(QString("piece"));

        QJsonObject piece = value.toObject();

        map[0].push_back(piece["0"].toArray()[0].toString());


        Game_View_Entity *entity_view = new Game_View_Entity(map,x,p->getCoordY(),p->getState());
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
        for(int i =0;i<9;i++)
        map[0].push_back(koopa["0"].toArray()[i].toString());
        for(int i =0;i<9;i++)
        map[1].push_back(koopa["1"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(carapace *g,int x)
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

        QJsonValue value = sett2.value(QString("carapace"));

        QJsonObject carapace = value.toObject();
        map[0].push_back(carapace["0"].toArray()[0].toString());
        for(int i =0;i<8;i++)
        map[1].push_back(carapace["1"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(plante *g,int x)
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

        QJsonValue value = sett2.value(QString("plante"));

        QJsonObject plante = value.toObject();
        for(int i =0;i<3;i++)
        map[0].push_back(plante["0"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(flamme *g,int x)
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

        QJsonValue value = sett2.value(QString("flamme"));

        QJsonObject flamme = value.toObject();
        for(int i =0;i<9;i++)
        map[0].push_back(flamme["0"].toArray()[i].toString());
        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}
Game_View_Entity *Game_View_Factory::create(thwomp *g,int x)
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

        QJsonValue value = sett2.value(QString("thwomp"));

        QJsonObject thwomp = value.toObject();
        map[0].push_back(thwomp["0"].toArray()[0].toString());
        map[1].push_back(thwomp["1"].toArray()[0].toString());
        map[2].push_back(thwomp["2"].toArray()[0].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}
Game_View_Entity *Game_View_Factory::create(bulletbill *g,int x)
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

        QJsonValue value = sett2.value(QString("bulletbill"));

        QJsonObject bulletbill = value.toObject();
        map[0].push_back(bulletbill["0"].toArray()[0].toString());
        map[1].push_back(bulletbill["1"].toArray()[0].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}
Game_View_Entity *Game_View_Factory::create(billblaster *g,int x)
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

        QJsonValue value = sett2.value(QString("billblaster"));

        QJsonObject billblaster = value.toObject();
        for(int i =0;i<5;i++)
        map[0].push_back(billblaster["0"].toArray()[i].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}
Game_View_Entity *Game_View_Factory::create(smoke *g,int x)
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

        QJsonValue value = sett2.value(QString("smoke"));

        QJsonObject smoke = value.toObject();
        map[0].push_back(smoke["0"].toArray()[0].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity *Game_View_Factory::create(mysteryblock *g,int x)
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

        QJsonValue value = sett2.value(QString("mysteryblock"));

        QJsonObject mysteryblock = value.toObject();
        map[0].push_back(mysteryblock["0"].toArray()[0].toString());
        map[1].push_back(mysteryblock["1"].toArray()[0].toString());

        Game_View_Entity *entity_view = new Game_View_Entity(map,x,g->getCoordY(),g->getState());

        return entity_view;
}

Game_View_Entity* Game_View_Factory::create(star *b, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("star"));

          QJsonObject star = value.toObject();

          map[0].push_back(star["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,b->getCoordY(),b->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(lifeup *b, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("lifeup"));

          QJsonObject lifeup = value.toObject();

          map[0].push_back(lifeup["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,b->getCoordY(),b->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(mushroom *b, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("mushroom"));

          QJsonObject mushroom = value.toObject();

          map[0].push_back(mushroom["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,b->getCoordY(),b->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(flower *b, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("flower"));

          QJsonObject flower = value.toObject();

          map[0].push_back(flower["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,b->getCoordY(),b->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(Chateau *c, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("chateau"));

          QJsonObject chateau = value.toObject();

          map[0].push_back(chateau["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,c->getCoordY(),c->getState());

          return entity_view;

}

Game_View_Entity* Game_View_Factory::create(spike *c, int x){


          QMap<int,QList<QString>> map;

          QString val;
          QFile file;
          file.setFileName(":images/images/Characters_Animations_Pattern.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();

          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();
          QJsonValue value = sett2.value(QString("spike"));

          QJsonObject spike = value.toObject();

          map[0].push_back(spike["0"].toArray()[0].toString());


          Game_View_Entity *entity_view = new Game_View_Entity(map,x,c->getCoordY(),c->getState());

          return entity_view;

}
