#include "racetype.h"
#include "ui_racetype.h"
#include "mainwindow.h"
#include <QMessageBox>

RaceType::RaceType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaceType)
{
    ui->setupUi(this);
}

RaceType::~RaceType()
{
    delete ui;
}

void RaceType::on_pushButton_clicked()
{
    RaceType::reject();
}

void RaceType::on_pushButton_2_clicked()
{
    QString type;
    type = ui->lineEdit->text();

    /*
    conn.connOpen();
    QSqlQuery query;
    query.prepare("INSERT INTO RaceType (type) VALUES ('"+type+"')");

    if(!query.exec( ))
        if(query.lastError().number() == 19)
            QMessageBox::critical(this,tr("Duplicate Entry"),tr("Race type may already exist!"));
        else
            qDebug()<<query.lastError();
    else
        QMessageBox::information(this,tr("Saved"),tr("Successfully added race type to database."));
        conn.connClose();
        ui->lineEdit->clear();
    */

}
