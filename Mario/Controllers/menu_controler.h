#ifndef MENU_CONTROLER_H
#define MENU_CONTROLER_H

#include "../Views/menu_view.h"
#include <QObject>

class Global_Views_Controller;
class Menu_Controler :  QObject
{
    Q_OBJECT
public:
    Menu_Controler(Global_Views_Controller *parent_obj);

    Menu_View* getScene();

private:
    Global_Views_Controller *parent;
    Menu_View *menu_view;;

public slots:
    void play();
    void select_level();
    void quit();
};

#endif // MENU_CONTROLER_H
