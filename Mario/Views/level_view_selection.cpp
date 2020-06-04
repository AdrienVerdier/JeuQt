#include "level_view_selection.h"

#include <QPainter>
#include <QDir>
#include <QGraphicsProxyWidget>

level_view_selection::level_view_selection(QString Path)
{
    QDir directory(Path);
    QStringList levels = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);

    QColor green70 = Qt::gray;
    QRectF *rect = new QRectF(0,0,500,500);
    QPen *pen = new QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    QPainter painter;
    painter.fillRect(*rect,Qt::Dense4Pattern);
    addRect(*rect,*pen,green70);

    list_widget = new QListWidget();
    foreach(QString filename, levels){
        list_level = new QListWidgetItem(filename,list_widget);
    }

    list_widget->setMaximumSize(350,300);
    list_widget->setMinimumSize(350,300);

    QGraphicsProxyWidget *proxy;
    proxy = addWidget(list_widget);
    proxy->setPos(250 - list_widget->geometry().width()/2,100);
    proxy = addWidget(bouton);
    proxy->setPos(250 - bouton->geometry().width()/2,450);

    list_widget->setCurrentRow(0);
}

QPushButton *level_view_selection::getBouton() const
{
    return bouton;
}

QListWidget *level_view_selection::getList_widget() const
{
    return list_widget;
}

void level_view_selection::setList_widget(QListWidget *value)
{
    list_widget = value;
}
