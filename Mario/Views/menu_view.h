#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class Menu_View : public QGraphicsScene
{
public:
    Menu_View();

    QPushButton *get_Bouton_play() ;
    QPushButton *get_Bouton_select() ;
    QPushButton *get_Bouton_quit();

private:
    QGraphicsProxyWidget *proxy;
    QPushButton *bouton_play = new QPushButton("Play");
    QPushButton *bouton_select = new QPushButton("Select Level");
    QPushButton *bouton_quit = new QPushButton("Exit");
};


#endif // MENU_VIEW_H
