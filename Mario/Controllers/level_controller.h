#ifndef LEVEL_CONTROLLER_H
#define LEVEL_CONTROLLER_H
#include "../Models/level.h"
#include <QObject>
#include <QTimer>
#include <QMap>


class Game_View;
class Level_Controller :QObject
{
    Q_OBJECT
public:
    Level_Controller();
    Game_View * getScene();

private:
    Game_View *game_view;
    Level * level;
    QList<Entity*> current_entity_list;// liste d'entity "courante" --> entity ayant un state à 1 et celles étant passé à 0
    QTimer *m_timer;
    QMap<Entity*, QMap<Entity*,int>> collision_List;

    void update_view();

public slots:
    void update_lvl();
};

#endif // LEVEL_CONTROLLER_H