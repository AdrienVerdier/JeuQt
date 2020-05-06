#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "backgrounditem.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void keyPressEvent( QKeyEvent * keyEvent);
    void keyReleaseEvent(  QKeyEvent * keyEvent );
    QGraphicsScene * scene;
    Player * player;
    BackgroundItem *m_sky;
    BackgroundItem *m_ground;
    void setQscrollBar(QScrollBar *b);


private:
        void gauche();
        void droite();
       QScrollBar *scroll;
       bool left;
       bool right;
       bool jump;

       enum keys
       {
           No_Key      = 0x00,
           Key_Up      = 0x01,
           Key_Down    = 0x02,
           Key_Right   = 0x04,
           Key_Left    = 0x08
       };
       unsigned int keyPressed;
       QTimer *m_timer;

    public slots:
    void keyTimer();



};
#endif // GAME_H
