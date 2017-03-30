#include "viewtable.h"
#include "ui_viewtable.h"

ViewTable::ViewTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTable)
{
    ui->setupUi(this);

    if(!db.isOpen())
    {
        MainWindow conn;
//        QSqlQueryModel *modal = new QSqlQueryModel();
        conn.connOpen();
//        QSqlQuery *qry = new QSqlQuery(conn.db);
//        qry->prepare("SELECT * FROM Car WHERE rowid >= 1");
//        qry->exec();
//        modal->setQuery(*qry);
//        ui->carView->setModel(modal);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

ViewTable::~ViewTable()
{
    delete ui;
}


void ViewTable::updateTable()
{
    int index = ui->tabWidget->currentIndex();
    if(index == 0)
    {
        QSqlQueryModel * modal=new QSqlQueryModel;
        modal->setQuery("SELECT * FROM Car WHERE rowid >= 1");
        ui->tableView->setModel(modal);
    }
    else if(index == 1)
    {
        QSqlQueryModel * carModal=new QSqlQueryModel;
        carModal->setQuery("SELECT * FROM Track WHERE rowid >= 1");
        ui->tableView_2->setModel(carModal);
    }
    else
    {
        QSqlQueryModel * racetypeModal=new QSqlQueryModel();
        racetypeModal->setQuery("SELECT * FROM RaceType WHERE rowid >= 1");
        ui->tableView_3->setModel(racetypeModal);
    }

}


void ViewTable::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        QSqlQueryModel * modal=new QSqlQueryModel;
        modal->setQuery("SELECT * FROM Car WHERE rowid >= 1");
        ui->tableView->setModel(modal);
    }
    else if(index == 1)
    {
        QSqlQueryModel * carModal=new QSqlQueryModel;
        carModal->setQuery("SELECT * FROM Track WHERE rowid >= 1");
        ui->tableView_2->setModel(carModal);
    }
    else
    {
        QSqlQueryModel * racetypeModal=new QSqlQueryModel();
        racetypeModal->setQuery("SELECT * FROM RaceType WHERE rowid >= 1");
        ui->tableView_3->setModel(racetypeModal);
    }
}

void ViewTable::on_addButton_clicked()
{
    int index = ui->tabWidget->currentIndex();
    if(index == 0)
    {
        Car car;
        car.setModal(true);
        car.exec();
        updateTable();


    }
    else if(index == 1)
    {

    }
    else
    {

    }
}

void ViewTable::on_editButton_clicked()
{
    int index = ui->tabWidget->currentIndex();
    if(index == 0)
    {
        qDebug()<<cIndex;
        Car car;
        car.setModal(true);
        car.ui->lineEdit_type->setText(typeC);
        car.ui->lineEdit_number->setText(numbC);
        car.ui->carView->selectRow(cIndex);
        car.exec();



    }
    else if(index == 1)
    {

    }
    else
    {

    }
}

void ViewTable::on_delButton_clicked()
{

}

void ViewTable::on_tableView_clicked(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    db.open();
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Car where type='"+val+"' or number='"+val+"' ");
    if(qry->exec())
    {

        while(qry->next())
        {
            typeC = qry->value(0).toString();
            numbC = qry->value(1).toString();
        }
        qDebug()<<typeC << numbC;
    cIndex = ui->tableView->currentIndex().row();
    }
    else
        qDebug()<<qry->lastError();


}
