#include "game_over_view.h"

#include <QLabel>
 #include <QCoreApplication>

Game_Over_View::Game_Over_View(QWidget *parent)
{

    setSceneRect(200,100,800,400);

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


    //connect(bouton, SIGNAL (released()), this, SLOT (handleButton()));

}

void Game_Over_View::handleButton()
{
   // change the text
   bouton->setText("Example");
   // resize button
   bouton->resize(100,100);
}
