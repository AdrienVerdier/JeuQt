#ifndef LEVEL_VIEW_SELECTION_H
#define LEVEL_VIEW_SELECTION_H

#include <QGraphicsScene>
#include <QListWidget>
#include <QPushButton>

class level_view_selection : public QGraphicsScene
{
public:
    level_view_selection(QString Path);

    QPushButton *getBouton() const;

    QListWidget *getList_widget() const;
    void setList_widget(QListWidget *value);

private:
    QListWidget *list_widget;
    QListWidgetItem *list_level;
    QString *level_selected;
    QPushButton *bouton = new QPushButton("Select Level");

};

#endif // LEVEL_VIEW_SELECTION_H
