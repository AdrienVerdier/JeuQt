#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "backgrounditem.h"

class Backgrounitem;

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QGraphicsScene * scene;
    Player * player;
    BackgroundItem *m_sky;
    BackgroundItem *m_ground;
    void setQscrollBar(QScrollBar *b);


private:
       QScrollBar *scroll;




};
#endif // GAME_H
