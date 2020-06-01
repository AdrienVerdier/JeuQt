#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <QList>
#include "mario.h"
#include "block.h"
#include "goomba.h"
#include "piece.h"

class Level
{
public:
    Level();
    QList<Entity*> * get_entity_list();
    QList<Entity*> * get_alive_entity_list();
    Mario * getPlayer();

    inline int getScore() const{
        return score;
    }

    inline void SetScore(int sc){
         score = sc;
    }

    inline int getNbVie() const{
        return nbVie;
    }

    inline void SetNbVie(int vies){
         nbVie = vies;
    }



private:
    Mario * player;
    QList<Entity*> * entity_list;
     QList<Entity*> * alive_entity_list;
     int score;
     int nbVie;
};

#endif // LEVEL_H
