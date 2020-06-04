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
    void hide_Menu();
    void show_current_level();

    Global_View *getView() const;


private:
    Global_View * main_view = new Global_View(this);
    QGraphicsScene *main_scene = new QGraphicsScene;

    QGraphicsView *level_view_container = new QGraphicsView;
    QGraphicsView *menu_view_container = new QGraphicsView;
    QGraphicsView *gameover_view_container = new QGraphicsView;
    QGraphicsView *select_level_view_container = new QGraphicsView;

    Level_Controller *level_controller;
    Menu_Controler *menu_controler;
    Game_Over_View *game_over_view;
};

#endif // GLOBAL_VIEWS_CONTROLLER_H
