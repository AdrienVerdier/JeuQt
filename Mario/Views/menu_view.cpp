#include "menu_view.h"

Menu_View::Menu_View()
{
    setSceneRect(200,100,800,400);
    setBackgroundBrush(Qt::transparent);

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_play);
    addItem(proxy);
    proxy->setPos(200,250);

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_select);
    addItem(proxy);
    proxy->setPos(200,300);

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_quit);
    addItem(proxy);
    proxy->setPos(200,350);

}

QPushButton *Menu_View::get_Bouton_play()
{
    return bouton_play;
}

QPushButton *Menu_View::get_Bouton_select()
{
    return bouton_select;
}

QPushButton *Menu_View::get_Bouton_quit()
{
    return bouton_quit;
}
