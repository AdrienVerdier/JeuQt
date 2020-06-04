#ifndef GLOBAL_VIEWS_CONTROLLER_H
#define GLOBAL_VIEWS_CONTROLLER_H

#include "../Views/global_view.h"
#include "../Views/game_over_view.h"
#include "menu_controler.h"
#include "level_controller.h"
#include <QStackedWidget>

class Global_Views_Controller
{
public:
    Global_Views_Controller();

    void display_Level(QString path);
    void display_GameOver();
    void display_Menu();
    void display_Level_Menu();
    void display_level_completed();
    void hide_GameOver();
    void hide_Menu();
    void hide_Level_Menu();
    void hide_level_completed();
    void show_current_level();

    Global_View *getView() const;


    Level_Controller *getLevel_controller() const;

private:
    Global_View * main_view = new Global_View(this);
    QGraphicsScene *main_scene = new QGraphicsScene;

    QGraphicsView *level_view_container = new QGraphicsView;
    QGraphicsView *menu_view_container = new QGraphicsView;
    QGraphicsView *gameover_view_container = new QGraphicsView;
    QGraphicsView *select_level_view_container = new QGraphicsView;
    QGraphicsView *level_completed_view_container = new QGraphicsView;

    Level_Controller *level_controller;
    Menu_Controler *menu_controler;
    Game_Over_View *game_over_view;
};

#endif // GLOBAL_VIEWS_CONTROLLER_H
