#include <QApplication>
#include <QGraphicsView>

#include "Controllers/global_views_controller.h"





Global_Views_Controller * global_controller;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    global_controller = new Global_Views_Controller();
    global_controller->display_Level();
    global_controller->getView()->show();

    return a.exec();
}
