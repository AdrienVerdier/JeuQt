#include <QApplication>
#include <QGraphicsView>

#include "Controllers/global_views_controller.h"





Global_Views_Controller * global_controller;
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    global_controller = new Global_Views_Controller();
    global_controller->display_Level(":images/images/Niveau/NivTest.png");
    global_controller->getView()->show();

    return a.exec();
}
