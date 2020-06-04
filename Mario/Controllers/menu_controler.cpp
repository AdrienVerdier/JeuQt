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
    this->game_over_view = new Game_Over_View;
    this->level_completed_view = new  level_completed;
    connect(menu_view->get_Bouton_play(),SIGNAL(released()),this,SLOT(play()));
    connect(menu_view->get_Bouton_select(),SIGNAL(released()),this,SLOT(select_level()));
    connect(menu_view->get_Bouton_quit(),SIGNAL(released()),this,SLOT(quit()));
    connect(level_selection_menu->getBouton(),SIGNAL(released()),this,SLOT(level_selected()));
    connect(game_over_view->getBouton(),SIGNAL(released()),this,SLOT(play_again()));
    connect(game_over_view->getBouton_2(),SIGNAL(released()),this,SLOT(back_to_menu()));
    connect(level_completed_view->getBouton(),SIGNAL(released()),this,SLOT(play_again_level_completed()));
    connect(level_completed_view->getBouton_2(),SIGNAL(released()),this,SLOT(back_to_menu_level_completed()));

}

Menu_View *Menu_Controler::getScene()
{
    return menu_view;
}

level_view_selection *Menu_Controler::getLevel_selection_menu() const
{
    return level_selection_menu;
}

Game_Over_View *Menu_Controler::getGame_over_view() const
{
    return game_over_view;
}

level_completed *Menu_Controler::getLevel_completed_view() const
{
    return level_completed_view;
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
    parent->getLevel_controller()->setPath_level_en_cours(levelpath);
    parent->display_Level(levelpath);
    parent->hide_Menu();
    parent->getLevel_controller()->setPause(false);
}

void Menu_Controler::play_again()
{
    parent->hide_GameOver();
    parent->display_Level(parent->getLevel_controller()->getPath_level_en_cours());
}

void Menu_Controler::back_to_menu()
{
    parent->hide_GameOver();
    parent->display_Level(parent->getLevel_controller()->getPath_level_en_cours());
    parent->display_Menu();
}

void Menu_Controler::play_again_level_completed()
{
    parent->hide_level_completed();
    parent->display_Level(parent->getLevel_controller()->getPath_level_en_cours());
}

void Menu_Controler::back_to_menu_level_completed()
{
    parent->hide_level_completed();
    parent->display_Level(parent->getLevel_controller()->getPath_level_en_cours());
    parent->display_Menu();
}
