#include "game_over_view.h"

#include <QLabel>

Game_Over_View::Game_Over_View(QWidget *parent)
{

    setSceneRect(0,0,1280,700);

   QFont f( "Arial", 50, QFont::Bold);
    score =  new QLabel();
    score->setText("GAME OVER");
    score->setGeometry(QRect(300, 200,500, 100));
    score->setFont(f);
    score->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(score);




}
