#ifndef LEVEL_CONTROLLER_H
#define LEVEL_CONTROLLER_H
#include "../Models/level.h"
#include <QObject>
#include <QTimer>
#include <QMap>
#include <QMediaPlayer>

class Game_View;
class Global_Views_Controller;
class Level_Controller :QObject
{
    Q_OBJECT
public:
    Level_Controller( Global_Views_Controller *p=0);
    Game_View * getScene();
    void select_display_element();
    void NewLevel(QString path);
    void escape_key_pressed();

    bool getPause() const;
    void setPause(bool value);

    QString getPath_level_en_cours() const;

private:
    QString path_level_en_cours;
    Global_Views_Controller *pere;
    bool reset;
    Game_View *game_view;
    Level * level;
    QList<Entity*> current_entity_list;// liste d'entity "courante" --> entity ayant un state à 1 et celles étant passé à 0
    QTimer *m_timer;
    QMap<Entity*, QMap<Entity*,int>> collision_List;
    bool pause;
    void update_view();

public slots:
    void update_lvl();

};

#endif // LEVEL_CONTROLLER_H
