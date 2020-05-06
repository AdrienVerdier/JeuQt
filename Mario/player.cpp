#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

int Player::get_debut_saut() const
{
    return this->debut_saut;
}

void Player::set_debut_saut(int debut_saut)
{
    this->debut_saut = debut_saut;
}

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 2000)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){

        set_debut_saut(pos().y());
        timer = new QTimer(this);
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(jump()));
        timer->start(50);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}

void Player::jump(){
    if (pos().y() > 300)
        setPos(x(),y()-10);
    else
    {
        timer->stop();
        timer = new QTimer(this);
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(descente()));
        timer->start(50);
    }
}

void Player::descente(){
    if (pos().y() < 500)
        setPos(x(),y()+10);
    else
        timer->stop();
}
