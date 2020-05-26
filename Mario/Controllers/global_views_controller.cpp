#include "global_views_controller.h"
#include "../Views/game_view.h"

Global_Views_Controller::Global_Views_Controller()
{
    view = new Global_View();
    level_controller = new Level_Controller();

}

void Global_Views_Controller::display_Level()
{
   view->setScene(level_controller->getScene());
}

Global_View *Global_Views_Controller::getView() const
{
    return view;
}

