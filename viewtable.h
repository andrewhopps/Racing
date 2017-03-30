#ifndef VIEWTABLE_H
#define VIEWTABLE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QDebug>
#include <QSqlQuery>
#include <mainwindow.h>
#include "car.h"
#include "ui_car.h"

namespace Ui {
class ViewTable;
}

class ViewTable : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QString numbC, typeC;
    int cIndex;

    explicit ViewTable(QWidget *parent = 0);
    ~ViewTable();

private slots:

    void updateTable();

    void on_tabWidget_tabBarClicked(int index);

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ViewTable *ui;
};

#endif // VIEWTABLE_H
