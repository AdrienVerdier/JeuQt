#include <QApplication>
#include <QGraphicsView>

#include "Controllers/global_views_controller.h"





Global_Views_Controller * global_controller;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    global_controller = new Global_Views_Controller();
    global_controller->display_Level(":images/images/Niveau/Niv1.png");
    global_controller->getView()->show();
    global_controller->display_Menu();

    return a.exec();
}
