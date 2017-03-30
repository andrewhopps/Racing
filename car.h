#ifndef CAR_H
#define CAR_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include <mainwindow.h>

namespace Ui {
class Car;
}

class Car : public QDialog
{
    Q_OBJECT

public:
    Ui::Car *ui;

    int val = 1;
    QSqlDatabase db;



    explicit Car(QWidget *parent = 0);
    ~Car();

private slots:
    void on_addButton_clicked();

    void on_closeButton_clicked();

    void on_updateButton_clicked();

    void on_carView_clicked(const QModelIndex &index);

    void on_deleteButton_clicked();

private:


protected:
    void closeEvent(QCloseEvent *event);

};

#endif // CAR_H
