#ifndef GLOBAL_VIEWS_CONTROLLER_H
#define GLOBAL_VIEWS_CONTROLLER_H

#include "../Views/global_view.h"
#include "../Views/game_over_view.h"
#include "level_controller.h"

class Global_Views_Controller
{
public:
    Global_Views_Controller();
    void display_Level(QString path);

     void display_GameOver();

    Global_View *getView() const;


private:
    Global_View * view;
    Level_Controller * level_controller;
    Game_Over_View *game_over_view;
};

#endif // GLOBAL_VIEWS_CONTROLLER_H
