#include "track.h"
#include "ui_track.h"
#include "mainwindow.h"
#include <ui_mainwindow.h>

Track::Track(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Track)
{
    ui->setupUi(this);

}

Track::~Track()
{
    delete ui;
}



void Track::on_pushButton_2_clicked()
{
/*
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("SELECT name FROM Track");
    query->exec();
    modal->setQuery(*query);
    Ui::MainWindow::trackSelect->setModel(modal);
*/

    Track::reject();
}

void Track::on_saveButton_clicked()
{
    QString name,length,surface,address,city,state,zip,phone;
    name = ui->trackName->text();
    length = ui->trackLength->text();
    surface = ui->trackSurface->text();
    address = ui->trackAddress->text();
    city = ui->trackCity->text();
    state = ui->trackState->currentText();
    zip = ui->trackZip->text();
    phone = ui->trackPhone->text();


    conn.connOpen();
    QSqlQuery query;
    query.prepare("INSERT INTO Track (name,length,surface,address,city,state,zip,phone) VALUES ('"+name+"','"+length+"','"+surface+"','"+address+"','"+city+"','"+state+"','"+zip+"','"+phone+"')");

    if(!query.exec( ))
        if(query.lastError().number() == 19)
            QMessageBox::critical(this,tr("Duplicate Entry"),tr("Track may already exist!"));
        else
            qDebug()<<query.lastError();
    else
        QMessageBox::information(this,tr("Saved"),tr("Successfully added track to database."));
        ui->trackName->clear();
        ui->trackLength->clear();
        ui->trackSurface->clear();
        ui->trackAddress->clear();
        ui->trackCity->clear();
        ui->trackState->clear();
        ui->trackZip->clear();
        ui->trackPhone->clear();

}


