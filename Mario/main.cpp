#include <QApplication>
#include <QGraphicsView>

#include "Views/viewtest.h"





ViewTest *v;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    v = new ViewTest();
    v->show();

    return a.exec();
}
