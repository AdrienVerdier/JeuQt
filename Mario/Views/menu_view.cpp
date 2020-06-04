#include "menu_view.h"
#include <qpainter.h>
#include <QtDebug>

Menu_View::Menu_View()
{
    QColor green70 = Qt::green;
    QRectF *rect = new QRectF(0,0,400,400);
    QPen *pen = new QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    QPainter painter;
    painter.setBrush(green70);
    painter.fillRect(*rect,Qt::Dense4Pattern);
    green70.setAlphaF( 0.4 );
    addRect(*rect,*pen,green70);



    bouton_play->setMinimumSize(QSize(200,30));
    bouton_select->setMinimumSize(QSize(200,30));
    bouton_quit->setMinimumSize(QSize(200,30));

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_play);
    addItem(proxy);
    proxy->setPos(200 - bouton_play->geometry().width()/2,150);

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_select);
    addItem(proxy);
    proxy->setPos(200 - bouton_select->geometry().width()/2,200);

    proxy  = new QGraphicsProxyWidget();
    proxy->setWidget(bouton_quit);
    addItem(proxy);
    proxy->setPos(200 - bouton_quit->geometry().width()/2,250);

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
