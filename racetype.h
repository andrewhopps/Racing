#ifndef RACETYPE_H
#define RACETYPE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class RaceType;
}

class RaceType : public QDialog
{
    Q_OBJECT

public:
    MainWindow conn;
    explicit RaceType(QWidget *parent = 0);
    ~RaceType();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RaceType *ui;
};

#endif // RACETYPE_H
