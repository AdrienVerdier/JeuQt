#include "level_completed.h"

level_completed::level_completed()
{
    setSceneRect(0,0,800,400);

   QFont f( "Arial", 50, QFont::Bold);
    text =  new QLabel();
    text->setText("LEVEL COMPLETED");
    text->setGeometry(QRect(100, 0,600, 100));
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

QPushButton *level_completed::getBouton() const
{
    return bouton;
}

QPushButton *level_completed::getBouton_2() const
{
    return bouton_2;
}
