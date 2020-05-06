#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include<QTimer>

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

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    set_en_l_air(false);
}

QTimer* Player::getTimer(){
    return timer;
}

void Player::setImg(){
    QImage img;
    img.load(":images/images/mario.png");
    int subImageWidth = img.width() / 21;
    pixmaps.clear();
    currentPixmap = 0;
    for (int i = 0; i < 21; i++)
    {
        QImage subImage = img.copy(i * subImageWidth,0,subImageWidth , img.height());
        pixmaps.push_back(QPixmap::fromImage(subImage));
    }

    connect(&timerAnim, SIGNAL(timeout()), SLOT(changeImage()));
    timerAnim.start(100);
    changeImage();
}

void Player::changeImage()
{
    if (currentPixmap >= pixmaps.length())
        currentPixmap = 0;

    this->setPixmap(pixmaps.at(currentPixmap));

    currentPixmap++;
}

void Player::sauter(){
    if(!get_en_l_air())
    {
        set_en_l_air(true);
        set_debut_saut(pos().y());
        timer = new QTimer(this);
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(jump()));
        timer->start(30);
    }

}





void Player::jump(){
    if (pos().y() > 400)
        setPos(x(),y()-10);
    else
    {
        timer->stop();
        timer = new QTimer(this);
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(descente()));
        timer->start(30);
    }
}


void Player::descente(){
    if (pos().y() < 560)
        setPos(x(),y()+10);
    else
    {
        getTimer()->stop();
        set_en_l_air(false);
    }
}


