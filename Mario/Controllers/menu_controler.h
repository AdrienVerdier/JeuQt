#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H

#include "../Views/menu_view.h"
#include "../Views/level_view_selection.h"
#include <QObject>

class Global_Views_Controller;
class Menu_Controler :  QObject
{
    Q_OBJECT
public:
    Menu_Controler(Global_Views_Controller *parent_obj);

    Menu_View* getScene();

    void connectslotlevel();

private:
    Global_Views_Controller *parent;
    Menu_View *menu_view;
    level_view_selection *level_selection_menu;

public slots:
    void play();
    void select_level();
    void quit();
    void level_selected();
};

#endif // MENU_CONTROLER_H
