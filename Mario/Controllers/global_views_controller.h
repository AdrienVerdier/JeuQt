#ifndef GLOBAL_VIEWS_CONTROLLER_H
#define GLOBAL_VIEWS_CONTROLLER_H

#include "../Views/global_view.h"
#include "level_controller.h"

class Global_Views_Controller
{
public:
    Global_Views_Controller();
    void display_Level();

    Global_View *getView() const;


private:
    Global_View * view;
    Level_Controller * level_controller;
};

#endif // GLOBAL_VIEWS_CONTROLLER_H
