#ifndef GLOBAL_VIEWS_CONTROLLER_H
#define GLOBAL_VIEWS_CONTROLLER_H

#include "../Views/global_view.h"
#include "../Views/game_over_view.h"
#include "menu_controler.h"
#include "level_controller.h"
#include <QStackedWidget>

class Menu_Controler;
class Global_Views_Controller
{
public:
    Global_Views_Controller();

    void display_Level(QString path);
    void display_GameOver();

    Global_View *getView() const;


private:
    Global_View * main_view = new Global_View;
    QGraphicsScene *main_scene = new QGraphicsScene;

    QGraphicsView *level_view_container = new QGraphicsView;
    QGraphicsView *menu_view_container = new QGraphicsView;
    QGraphicsView *gameover_view_container = new QGraphicsView;

    Level_Controller *level_controller;
    Menu_Controler *menu_controler;

    Game_Over_View *game_over_view;

    QStackedWidget *qstack;
};

#endif // GLOBAL_VIEWS_CONTROLLER_H
