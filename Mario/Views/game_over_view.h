#ifndef GAME_OVER_VIEW_H
#define GAME_OVER_VIEW_H

#include <QGraphicsScene>
#include <QLabel>

class Game_Over_View : public QGraphicsScene
{
public:
    Game_Over_View(QWidget *parent = 0 );

private:
    QLabel *score;
};

#endif // GAME_OVER_VIEW_H
