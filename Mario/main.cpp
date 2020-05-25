#include <QApplication>
#include <QGraphicsView>
#include "Views/game_view.h"
#include "Models/mario.h"
#include <unistd.h>





QGraphicsView *v;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    v = new QGraphicsView();
    v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    v->setFixedSize(1280,700);

    Game_View *g = new Game_View();

    v->setScene(g);


    Mario *m = new Mario();
    m->setDisplay(true);
    m->setCoordX(100);
    m->setCoordY(100);
    m->setState(1);

    g->paint(m);


    v->show();
    int cpt = 0;
    unsigned int microseconds = 3000;
/*
    while(cpt<10000){
      g->paint(m);

      usleep(microseconds);
      cpt++;
    }*/

    return a.exec();
}
