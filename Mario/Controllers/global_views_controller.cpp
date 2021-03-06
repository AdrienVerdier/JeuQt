#include "global_views_controller.h"
#include "../Views/game_view.h"

Global_Views_Controller::Global_Views_Controller()
{
    main_view->setScene(main_scene);

    level_controller = new Level_Controller(this);
    menu_controler = new Menu_Controler(this);

    level_view_container->setFixedSize(1280,700);
    level_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    level_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menu_view_container->setFixedSize(1280,700);
    menu_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    menu_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    menu_view_container->setStyleSheet("background: transparent");

    gameover_view_container->setFixedSize(1280,700);
    gameover_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameover_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameover_view_container->setStyleSheet("background: transparent");

    select_level_view_container->setFixedSize(1280,700);
    select_level_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    select_level_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    select_level_view_container->setStyleSheet("background: transparent");

    level_completed_view_container->setFixedSize(1280,700);
    level_completed_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    level_completed_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    level_completed_view_container->setStyleSheet("background: transparent");

    level_view_container->setScene(level_controller->getScene());
    menu_view_container->setScene(menu_controler->getScene());
    select_level_view_container->setScene(menu_controler->getLevel_selection_menu());
    gameover_view_container->setScene(menu_controler->getGame_over_view());
    level_completed_view_container->setScene(menu_controler->getLevel_completed_view());

    main_scene->addWidget(level_view_container)->setPos(0,0);
    main_scene->addWidget(gameover_view_container)->setPos(0,0);
    main_scene->addWidget(menu_view_container)->setPos(0,0);
    main_scene->addWidget(select_level_view_container)->setPos(0,0);
    main_scene->addWidget(level_completed_view_container)->setPos(0,0);

    level_view_container->hide();
    menu_view_container->hide();
    gameover_view_container->hide();
    select_level_view_container->hide();
    level_completed_view_container->hide();

}

void Global_Views_Controller::display_Level(QString path)
{
    level_controller->setPause(true);
    level_view_container->show();
    level_view_container->setFocus();
    level_controller->NewLevel(path);
}

void Global_Views_Controller::display_GameOver()
{
    gameover_view_container->show();
    gameover_view_container->setFocus();
}

void Global_Views_Controller::display_Menu()
{
    if(!menu_view_container->isVisible()){
        level_controller->setPause(true);
        menu_view_container->show();
        menu_view_container->setFocus();
    }
}

void Global_Views_Controller::display_Level_Menu()
{
    select_level_view_container->show();
}

void Global_Views_Controller::display_level_completed()
{
    level_completed_view_container->show();
}

void Global_Views_Controller::hide_GameOver()
{
    gameover_view_container->hide();
}

void Global_Views_Controller::hide_Menu()
{
    menu_view_container->hide();
}

void Global_Views_Controller::hide_Level_Menu()
{
    select_level_view_container->hide();
}

void Global_Views_Controller::hide_level_completed()
{
    level_completed_view_container->hide();
}

void Global_Views_Controller::show_current_level()
{
    level_controller->setPause(false);
    level_view_container->show();
    level_view_container->setFocus();
}

Global_View *Global_Views_Controller::getView() const
{
    return main_view;
}

Level_Controller *Global_Views_Controller::getLevel_controller() const
{
    return level_controller;
}

