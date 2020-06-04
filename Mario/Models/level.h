#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include "alive_entity.h"
#include <QList>
#include "mario.h"
#include "block.h"

class Level
{
public:
    Level(QString path);
    QList<Entity*> * get_entity_list();
    QList<Alive_Entity*> * get_alive_entity_list();
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



    int getCoord_x_cp() const;
    void setCoord_x_cp(int value);

    int getCoord_y_cp() const;
    void setCoord_y_cp(int value);

private:
    Mario * player;
    QList<Entity*> * entity_list;
    QList<Alive_Entity*> * alive_entity_list;
    int score;
    int nbVie;
    int coord_x_cp;
    int coord_y_cp;
};

#endif // LEVEL_H
