#include "menu_controler.h"
#include "global_views_controller.h"
#include <QObject>
#include <QDebug>
#include <QApplication>

Menu_Controler::Menu_Controler(Global_Views_Controller *parent_obj)
{
    this->parent = parent_obj;
    this->menu_view = new Menu_View();
    this->level_selection_menu = new level_view_selection();
    connect(menu_view->get_Bouton_play(),SIGNAL(released()),this,SLOT(play()));
    connect(menu_view->get_Bouton_select(),SIGNAL(released()),this,SLOT(select_level()));
    connect(menu_view->get_Bouton_quit(),SIGNAL(released()),this,SLOT(quit()));
}

Menu_View *Menu_Controler::getScene()
{
    return menu_view;
}

void Menu_Controler::play()
{
    parent->hide_Menu();
    parent->show_current_level();
}

void Menu_Controler::select_level()
{

}

void Menu_Controler::quit()
{
    QApplication::quit();
}

void Menu_Controler::level_selected()
{

}
