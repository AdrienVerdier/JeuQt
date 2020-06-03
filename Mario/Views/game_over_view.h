#ifndef GAME_OVER_VIEW_H
#define GAME_OVER_VIEW_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>


class Game_Over_View : public QGraphicsScene
{
public:
    Game_Over_View(QWidget *parent = 0 );

private:
    QLabel *text;
    QPushButton *bouton;
    QGraphicsProxyWidget *proxy;
};

#endif // GAME_OVER_VIEW_H
