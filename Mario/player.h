#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:

    int get_debut_saut() const;
    void set_debut_saut(int debut_saut);
    bool get_en_l_air() const;
    void set_en_l_air(bool en_l_air);
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
private :
    int debut_saut;
    bool en_l_air;
    QTimer *timer;
public slots:
    void jump();
    void descente();
};

#endif // PLAYER_H
