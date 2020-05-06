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


void Game::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (player->pos().x() > 0)
        player->setPos(player->pos().x()-10,player->pos().y());
        if(player->pos().x()>=640 && player->pos().x()<=7380){
            m_sky->setPos(m_sky->pos().x()-10,m_sky->pos().y());
            this->scroll->setValue( scroll->value()-10);

        }
    }
    else if (event->key() == Qt::Key_Right){
        if (player->pos().x() + 100 < 8000)
        player->setPos(player->pos().x()+10,player->pos().y());

        if(player->pos().x()>=640 && player->pos().x()<=7380){
            this->scroll->setValue( scroll->value()+10);
            m_sky->setPos(m_sky->pos().x()+10,m_sky->pos().y());
        }

    }
    else if (event->key() == Qt::Key_Up){
        player->sauter();
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
}
