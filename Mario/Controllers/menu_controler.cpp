#include "menu_controler.h"
#include "global_views_controller.h"

Menu_Controler::Menu_Controler(Global_Views_Controller *parent_obj)
{
    this->parent = parent_obj;
    connect(menu_view->getBouton_play(),SIGNAL(released()),this,SLOT(play()));
}

Menu_View *Menu_Controler::getScene()
{
    return menu_view;
}

void Menu_Controler::play()
{
    parent->display_Level("");
}
