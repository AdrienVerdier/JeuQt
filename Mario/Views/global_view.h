#ifndef GLOBAL_VIEW_H
#define GLOBAL_VIEW_H


#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../Tools/controls.h"

class Global_Views_Controller;
class Global_View :  public QGraphicsView
{
public:
    Global_View(Global_Views_Controller *parent);
};

#endif // GLOBAL_VIEW_H
