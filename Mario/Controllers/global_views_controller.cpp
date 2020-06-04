#include "global_views_controller.h"
#include "../Views/game_view.h"

Global_Views_Controller::Global_Views_Controller()
{
    main_view->setScene(main_scene);

    level_controller = new Level_Controller(this);
    menu_controler = new Menu_Controler(this);
    game_over_view = new Game_Over_View();

    level_view_container->setFixedSize(1280,700);
    level_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    level_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menu_view_container->setFixedSize(500,300);

    gameover_view_container->setFixedSize(800,400);
    gameover_view_container->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameover_view_container->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    level_view_container->setScene(level_controller->getScene());
    menu_view_container->setScene(menu_controler->getScene());
    gameover_view_container->setScene(game_over_view);

    qstack = new QStackedWidget;
    main_scene->addWidget(qstack);
    qstack->addWidget(menu_view_container);
    qstack->addWidget(gameover_view_container);
    qstack->addWidget(level_view_container);


    level_view_container->hide();
    menu_view_container->hide();
    gameover_view_container->hide();

}

void Global_Views_Controller::display_Level(QString path)
{
    level_view_container->show();
    level_view_container->setFocus();
    level_controller->NewLevel(path);
}

void Global_Views_Controller::display_GameOver()
{
    gameover_view_container->show();
    qstack->widget(qstack->indexOf(gameover_view_container))->move(200,100);

}

Global_View *Global_Views_Controller::getView() const
{
    return main_view;
}

