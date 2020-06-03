#include "game_over_view.h"

#include <QLabel>

Game_Over_View::Game_Over_View(QWidget *parent)
{

    setSceneRect(0,0,1280,700);

   QFont f( "Arial", 50, QFont::Bold);
    text =  new QLabel();
    text->setText("GAME OVER");
    text->setGeometry(QRect(300, 200,500, 100));
    text->setFont(f);
    text->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(text);

    bouton = new QPushButton("Mon bouton entre en scène !");

        proxy = new QGraphicsProxyWidget();
        proxy->setWidget(bouton);
    this->addItem(proxy);




}
