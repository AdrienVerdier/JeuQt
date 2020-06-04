#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H

#include "../Views/menu_view.h"
#include "global_views_controller.h"

class Global_Views_Controller;
class Menu_Controler :  QObject
{
public:
    Menu_Controler(Global_Views_Controller *parent_obj);

    Menu_View* getScene();

private:
    Global_Views_Controller *parent;
    Menu_View *menu_view = new Menu_View;

public slots:
    void play();
};

#endif // MENU_CONTROLER_H
