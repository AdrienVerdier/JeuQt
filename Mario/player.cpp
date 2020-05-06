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

bool Player::get_en_l_air() const
{
    return this->en_l_air;
}

void Player::set_en_l_air(bool en_l_air)
{
    this->en_l_air = en_l_air;
}

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
    set_en_l_air(false);
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
        if(!get_en_l_air())
        {
            set_en_l_air(true);
            set_debut_saut(pos().y());
            timer = new QTimer(this);
            QObject::connect(timer,SIGNAL(timeout()),this,SLOT(jump()));
            timer->start(50);
        }
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
    {
        timer->stop();
        set_en_l_air(false);
    }
}
