#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H

#include "../Views/menu_view.h"

class Menu_Controler
{
public:
    Menu_Controler();

    Menu_View* getScene();

private:
    Menu_View *menu_view = new Menu_View;
};

#endif // MENU_CONTROLER_H
