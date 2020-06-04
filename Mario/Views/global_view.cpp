#include "global_view.h"
#include "../Controllers/global_views_controller.h"

Global_View::Global_View(Global_Views_Controller *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,700);
}
