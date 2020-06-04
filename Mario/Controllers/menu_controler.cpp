#include "menu_controler.h"
#include "global_views_controller.h"
#include <QObject>
#include <QDebug>
#include <QApplication>

Menu_Controler::Menu_Controler(Global_Views_Controller *parent_obj)
{
    this->parent = parent_obj;
    this->menu_view = new Menu_View();
    this->level_selection_menu = new level_view_selection(":/images/images/Niveau");
    connect(menu_view->get_Bouton_play(),SIGNAL(released()),this,SLOT(play()));
    connect(menu_view->get_Bouton_select(),SIGNAL(released()),this,SLOT(select_level()));
    connect(menu_view->get_Bouton_quit(),SIGNAL(released()),this,SLOT(quit()));
    connect(level_selection_menu->getBouton(),SIGNAL(released()),this,SLOT(level_selected()));
}

Menu_View *Menu_Controler::getScene()
{
    return menu_view;
}

level_view_selection *Menu_Controler::getLevel_selection_menu() const
{
    return level_selection_menu;
}

void Menu_Controler::play()
{
    parent->hide_Menu();
    parent->show_current_level();
}

void Menu_Controler::select_level()
{
    parent->display_Level_Menu();
}

void Menu_Controler::quit()
{
    QApplication::quit();
}

void Menu_Controler::level_selected()
{
    parent->hide_Level_Menu();
    int currentrow = level_selection_menu->getList_widget()->currentRow();
    QString levelpath = level_selection_menu->getList_widget()->item(currentrow)->text();
    levelpath = ":images/images/Niveau/" + levelpath;
    parent->display_Level(levelpath);
    parent->hide_Menu();
    parent->getLevel_controller()->setPause(false);
}
