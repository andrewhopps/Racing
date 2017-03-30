#ifndef TRACK_H
#define TRACK_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"


namespace Ui {
class Track;
}

class Track : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit Track(QWidget *parent = 0);
    ~Track();

private slots:
    void on_pushButton_2_clicked();

    void on_saveButton_clicked();


private:
    Ui::Track *ui;
    QSqlDatabase mydb;
};

#endif // TRACK_H
