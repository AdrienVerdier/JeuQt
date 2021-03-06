#include "game_over_view.h"

#include <QLabel>
 #include <QCoreApplication>

Game_Over_View::Game_Over_View(QWidget *parent)
{

    setSceneRect(0,0,800,400);

   QFont f( "Arial", 50, QFont::Bold);
    text =  new QLabel();
    text->setText("GAME OVER");
    text->setGeometry(QRect(190, 0,500, 100));
    text->setFont(f);
    text->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(text);

    bouton = new QPushButton("Play again");

    proxy = addWidget(bouton);
    proxy->setPos(400-bouton->geometry().width()/2,100);

    bouton_2 = new QPushButton("Back to Menu");

    proxy = addWidget(bouton_2);
    proxy->setPos(400-bouton_2->geometry().width()/2,150);

}

QPushButton *Game_Over_View::getBouton() const
{
    return bouton;
}

QPushButton *Game_Over_View::getBouton_2() const
{
    return bouton_2;
}
