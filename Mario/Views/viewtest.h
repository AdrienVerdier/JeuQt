#ifndef VIEWTEST_H
#define VIEWTEST_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "Models/mario.h"

class Game_View;
class ViewTest :  public QGraphicsView
{
    Q_OBJECT
public:
    ViewTest(QWidget *parent =0);

private:
    QTimer *m_timer;
    Game_View *g;
    Mario *m;
    Mario *m2;

public slots:
    void changeImage();
};

#endif // VIEWTEST_H
