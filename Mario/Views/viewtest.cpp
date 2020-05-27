#include "viewtest.h"
#include "game_view.h"
#include <QTimer>


ViewTest::ViewTest(QWidget *parent)
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,700);

    g = new Game_View();

    setScene(g);


    m = new Mario();
    m->setDisplay(true);
    m->setCoordX(100);
    m->setCoordY(100);
    m->setState(1);


    m2 = new Mario();
    m2->setDisplay(true);
    m2->setCoordX(110);
    m2->setCoordY(100);
    m2->setState(1);

    g->paint(m);
    g->paint(m2);
    //QMap<Entity*,QList<Entity*>> list = g->get_list_collides();
    show();

    m_timer = new QTimer(this);
    QObject::connect(m_timer,SIGNAL(timeout()),this,SLOT(changeImage()));
    m_timer->start(80);



}

void ViewTest::changeImage()
{
    g->paint(m);
    g->paint(m2);
}
