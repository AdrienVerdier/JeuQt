#include "global_views_controller.h"
#include "../Views/game_view.h"

Global_Views_Controller::Global_Views_Controller()
{
    view = new Global_View();
    level_controller = new Level_Controller(this);
    game_over_view = new Game_Over_View();

}

void Global_Views_Controller::display_Level(QString path)
{
    view->setScene(level_controller->getScene());
    level_controller->NewLevel(path);
}

void Global_Views_Controller::display_GameOver()
{
    view->setScene(game_over_view);
}

Global_View *Global_Views_Controller::getView() const
{
    return view;
}

