#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QTimer>


void Game::setQscrollBar(QScrollBar *b){
    scroll = b;
}

void Game::gauche(){
    if (player->pos().x() > 0)
    player->setPos(player->pos().x()-10,player->pos().y());
    if(player->pos().x()>=640 && player->pos().x()<=7380){
        m_sky->setPos(m_sky->pos().x()-10,m_sky->pos().y());
        this->scroll->setValue( scroll->value()-10);

    }
}

void Game::droite(){
    if (player->pos().x() + 100 < 8000)
    player->setPos(player->pos().x()+10,player->pos().y());

    if(player->pos().x()>=640 && player->pos().x()<=7380){
        this->scroll->setValue( scroll->value()+10);
        m_sky->setPos(m_sky->pos().x()+10,m_sky->pos().y());
    }
}

void Game::keyPressEvent( QKeyEvent * keyEvent )
{
    if(keyEvent->key() == Qt::Key_Up && !keyEvent->isAutoRepeat())
    {
        keyPressed |= Key_Up;
    }
    if (keyEvent->key() == Qt::Key_Right && !keyEvent->isAutoRepeat())
    {
        keyPressed |= Key_Right;
    }
    if (keyEvent->key() == Qt::Key_Down && !keyEvent->isAutoRepeat())
    {
        keyPressed |= Key_Down;
    }
    if (keyEvent->key() == Qt::Key_Left && !keyEvent->isAutoRepeat())
    {
        keyPressed |= Key_Left;
    }
}

 void Game::keyReleaseEvent( QKeyEvent * keyEvent )
 {
    if(keyEvent->key() == Qt::Key_Up && !keyEvent->isAutoRepeat())
    {
        keyPressed &= ~Key_Up;
    }
    if (keyEvent->key() == Qt::Key_Right && !keyEvent->isAutoRepeat())
    {
        keyPressed &= ~Key_Right;
    }
    if (keyEvent->key() == Qt::Key_Down && !keyEvent->isAutoRepeat())
    {
        keyPressed &= ~Key_Down;
    }
    if (keyEvent->key() == Qt::Key_Left && !keyEvent->isAutoRepeat())
    {
        keyPressed &= ~Key_Left;
    }
 }



Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,8000,720); // make the scene 800x600 instead of infinity by infinity (default)

    m_sky = new BackgroundItem(QPixmap(":images/images/sky.png"));
    m_sky->setPos(0,0);
    scene->addItem(m_sky);

    //add ground
    m_ground = new BackgroundItem(QPixmap(":images/images/ground.png"));
    m_ground->setPos(0, 640 );
    scene->addItem(m_ground);




    show();
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,700);

    // create the player
    player = new Player();

    player->setImg();





    player->setPos(640,560); // TODO generalize to always be in the middle bottom of screen
    setQscrollBar( this->horizontalScrollBar());
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //QMediaPlayer * music = new QMediaPlayer();
    //music->setMedia(QUrl("ressource.qrc:/son/musique-mario-bros-officielle.mp3"));
    //music->play();

    keyPressed = No_Key;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(keyTimer()));
    m_timer->start(30);
}

void Game::keyTimer(){

    if(keyPressed & Key_Up)
        player->sauter();
    if(keyPressed & Key_Left)
        gauche();
    if(keyPressed & Key_Right)
        droite();


}

