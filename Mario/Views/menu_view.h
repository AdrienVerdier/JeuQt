#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class Menu_View : public QGraphicsScene
{
public:
    Menu_View();

    QPushButton *getBouton_play() const;

    QPushButton *getBouton_select() const;

    QPushButton *getBouton_quit() const;

private:
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    QPushButton *bouton_play = new QPushButton("Play");
    QPushButton *bouton_select = new QPushButton("Select Level");
    QPushButton *bouton_quit = new QPushButton("Exit");
};


#endif // MENU_VIEW_H
