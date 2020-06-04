#ifndef LEVEL_COMPLETED_H
#define LEVEL_COMPLETED_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class level_completed: public QGraphicsScene
{
public:
    level_completed();

    QPushButton *getBouton() const;

    QPushButton *getBouton_2() const;

private:
    QLabel *text;
    QPushButton *bouton;
    QPushButton *bouton_2;
    QGraphicsProxyWidget *proxy;
};

#endif // LEVEL_COMPLETED_H
