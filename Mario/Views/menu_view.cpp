#include "menu_view.h"

Menu_View::Menu_View()
{
    proxy->setWidget(bouton_play);
}

QPushButton *Menu_View::getBouton_play() const
{
    return bouton_play;
}

QPushButton *Menu_View::getBouton_select() const
{
    return bouton_select;
}

QPushButton *Menu_View::getBouton_quit() const
{
    return bouton_quit;
}
