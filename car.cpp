#include "car.h"
#include "ui_car.h"
#include <QMessageBox>

Car::Car(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Car)
{
    ui->setupUi(this);

//WORKING DONT FUCK WITH IT
    if(!db.isOpen())
    {
        MainWindow conn;
        QSqlQueryModel *modal = new QSqlQueryModel();
        conn.connOpen();
        QSqlQuery *qry = new QSqlQuery(conn.db);
        qry->prepare("SELECT * FROM Car WHERE rowid >= 1");
        qry->exec();
        modal->setQuery(*qry);
        ui->carView->setModel(modal);
    }


}

void Car::closeEvent(QCloseEvent *event)
{
    qDebug()<<("Close Event Here");

}

Car::~Car()
{
    delete ui;
}

//WORKING DONT FUCK WITH IT
void Car::on_addButton_clicked()
{
    QString cartype,carnumber;
    cartype=ui->lineEdit_type->text();
    carnumber=ui->lineEdit_number->text();

    if(carnumber.length() == 0 || cartype.length() == 0)
        QMessageBox::critical(this,tr("Error"),tr("Please enter both a type and number."));
    else
    {
        MainWindow conn;
        QSqlQuery *qry = new QSqlQuery(conn.db);
        qry->prepare("INSERT INTO Car (type,number) VALUES ('"+cartype+"','"+carnumber+"')");

        if(!qry->exec( ))
            if(qry->lastError().number() == 19)
                QMessageBox::critical(this,tr("Duplicate Entry"),tr("Car number already exists!"));
            else
                qDebug()<<qry->lastError();
        else{
            QMessageBox::information(this,tr("Saved"),tr("Successfully added car to database."));
            ui->lineEdit_type->setText(cartype);
            ui->lineEdit_number->setText(carnumber);
            QSqlQueryModel *modal = new QSqlQueryModel();
            qry->prepare("SELECT * FROM Car WHERE rowid > 0");
            qry->exec();
            modal->setQuery(*qry);
            ui->carView->setModel(modal);
        }


    }
}

//WORKING DONT FUCK WITH IT
void Car::on_closeButton_clicked()
{
    Car::close();
}

//WORKING DONT FUCK WITH IT
void Car::on_updateButton_clicked()
{
    QString cartype,carnumber;
    cartype=ui->lineEdit_type->text();
    carnumber=ui->lineEdit_number->text();
    int row = ui->carView->selectionModel()->currentIndex().row() + val;



    if(carnumber.length() == 0 || cartype.length() == 0)
        QMessageBox::critical(this,tr("Error"),tr("Please enter both a type and number."));
    else
    {
        MainWindow conn;
        QSqlQuery *qry = new QSqlQuery(conn.db);
        qry->prepare("UPDATE Car SET type='"+cartype+"', number='"+carnumber+"' WHERE (rowid = ?)");
        qry->addBindValue(row);
        if(!qry->exec( ))
            {
                    qDebug()<<qry->lastError();
            }
        else{
            QMessageBox::information(this,tr("Saved"),tr("Successfully updated car."));
            QSqlQueryModel * modal=new QSqlQueryModel();
            qry->prepare("SELECT * FROM Car WHERE rowid > 0");
            qry->exec();
            modal->setQuery(*qry);
            ui->carView->setModel(modal);
            ui->lineEdit_type->clear();
            ui->lineEdit_number->clear();
        }

     }
}

//WORKING DONT FUCK WITH IT
void Car::on_carView_clicked(const QModelIndex &index)
{
    MainWindow conn;
    QSqlQuery *qry = new QSqlQuery(conn.db);


    int row = ui->carView->selectionModel()->currentIndex().row() + val;
    qDebug() << row;
    qry->prepare("SELECT * FROM Car WHERE (rowid = ?)");
    qry->addBindValue(row);
    if(qry->exec())
    {
        while(qry->next())
        {
            qDebug() << qry->value(0) << qry->value(1);
            ui->lineEdit_type->setText(qry->value(0).toString());
            ui->lineEdit_number->setText(qry->value(1).toString());
        }

    }

}

//WORKING DONT FUCK WITH IT
void Car::on_deleteButton_clicked()
{
    int row = ui->carView->selectionModel()->currentIndex().row() + val;
    MainWindow conn;
    QSqlQuery *qry = new QSqlQuery(conn.db);
    qry->prepare("DELETE FROM Car WHERE (rowid = ?)");
    qry->addBindValue(row);
    if(qry->exec()){
        QSqlQueryModel * modal=new QSqlQueryModel();
        qry->prepare("SELECT * FROM Car WHERE rowid > 0");
        qry->exec();
        modal->setQuery(*qry);
        ui->carView->setModel(modal);
        ui->lineEdit_type->clear();
        ui->lineEdit_number->clear();
        qry->prepare("VACUUM");
        qry->exec();
    }
}
