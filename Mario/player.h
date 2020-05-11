#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QScrollBar>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    int get_debut_saut() const;
    void set_debut_saut(int debut_saut);
    bool get_en_l_air() const;
    void set_en_l_air(bool en_l_air);
    Player(QGraphicsItem * parent=0);
    QTimer* getTimer();
    void setImg();
    void sauter();
    void animImmo();
    void animMarcheGauche();
    void animMarcheDroite();


private :
    int debut_saut;
    bool en_l_air;
    QTimer *timer;
    int currentPixmap;
    QList<QPixmap> pixmaps;
    QTimer timerAnim;

public slots:
    void jump();
    void descente();
    void changeImage();



};

#endif // PLAYER_H
