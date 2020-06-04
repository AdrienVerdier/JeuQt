#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H

#include "../Views/menu_view.h"
#include "../Views/level_view_selection.h"
#include "../Views/game_over_view.h"
#include "../Views/level_completed.h"
#include <QObject>

class Global_Views_Controller;
class Menu_Controler :  QObject
{
    Q_OBJECT
public:
    Menu_Controler(Global_Views_Controller *parent_obj);

    Menu_View* getScene();

    void connectslotlevel();

    level_view_selection *getLevel_selection_menu() const;

    Game_Over_View *getGame_over_view() const;

    level_completed *getLevel_completed_view() const;

private:
    Global_Views_Controller *parent;
    Menu_View *menu_view;
    level_view_selection *level_selection_menu;
    Game_Over_View *game_over_view;
    level_completed *level_completed_view;

public slots:
    void play();
    void select_level();
    void quit();
    void level_selected();
    void play_again();
    void back_to_menu();
    void play_again_level_completed();
    void back_to_menu_level_completed();
};

#endif // MENU_CONTROLER_H
