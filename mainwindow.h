#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "car.h"
#include <QHBoxLayout>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    //QGraphicsScene *scene;
    //QGraphicsRectItem *rect;

    QSqlDatabase db;
    QString aPath;
    QString dPath;


   void updateWindow() //Fully Populates All Fields Properly
    {

        if(!modal)
        {
            modal=new QSqlQueryModel(this);
            ui->carSelect->setModel(modal);
        }
        modal->setQuery("SELECT type || ' ' || number FROM Car WHERE rowid >= 1");
        ui->carSelect->setCurrentIndex(0);

        if(!carModal)
        {
            carModal=new QSqlQueryModel(this);
            ui->trackSelect->setModel(carModal);
        }
        carModal->setQuery("SELECT name FROM Track WHERE rowid >= 1");
        ui->trackSelect->setCurrentIndex(0);

        if(!racetypeModal)
        {
            racetypeModal=new QSqlQueryModel(this);
            ui->raceSelect->setModel(racetypeModal);
        }
        racetypeModal->setQuery("SELECT type FROM RaceType WHERE rowid >= 1");
        ui->raceSelect->setCurrentIndex(0);

        checkCars();

     }

   void newCarClicked(int index){
       switch(index){
       case 0:{
           qDebug() << "First";
           break;
       }
       case 1:
           qDebug() << "Second";
           break;
       default:break;

   }
   }


    void checkCars()
    {
        QHBoxLayout *hlayout = new QHBoxLayout();
        ui->scrollArea_2->setWidget(ui->frame);
        ui->frame->setLayout(hlayout);

        QSqlQuery *qry = new QSqlQuery(db);
        qry->prepare("SELECT type || ' ' || number FROM Car WHERE rowid >= 2");
        if(qry->exec())
        {
            int index = 0;
            while(qry->next())
            {
            QString cName;
            cName = qry->value(0).toString();
            QPushButton *newCar = new QPushButton(cName);
            newCar->setStyleSheet("background-color: rgb(240, 240, 240);"
                                  "background-image: url(:/Resources/Images/Resources/Images/carButton.png);"
                                  "background-repeat: no-repeat;"
                                  "background-attachment: fixed;"
                                  "background-position: center;");
            newCar->setFixedSize(213, 108);
            newCar->setIconSize(QSize(200,100));
            hlayout->addWidget(newCar);
            connect(newCar, &QPushButton::clicked, newCar, [=]{newCarClicked(index);});
            index++;
            }
        }

    }


    bool dbExists()
    {
        if(QFileInfo(dPath).exists()){
            qDebug()<<("Using Found Database.");
            qDebug()<<dPath;
            return true;
        }
        else{
            createDB();
        }
    }

    void createDB()
    {
        qDebug() << ("Creating New Database");
        connOpen();
        QSqlQuery *qry = new QSqlQuery(db);
        qry->prepare("CREATE TABLE IF NOT EXISTS Car"
                   "(type varchar(25), "
                   "number integer NOT NULL)");
        if(qry->exec())
        {
            if(qry->exec())
            {
                qry->prepare("INSERT INTO Car(type,number) VALUES('Select or', 'add a car.')");
                qry->exec();
            }
            else
                qDebug()<<qry->lastError();
        }
        else
            qDebug()<<qry->lastError();

        qry->prepare("CREATE TABLE IF NOT EXISTS Track "
                   "(name varchar(50) NOT NULL, "
                   "length varchar(6), "
                   "surface varchar(12), "
                   "address varchar(30), "
                   "city varchar(25), "
                   "state varchar(2), "
                   "zip varchar(5), "
                   "phone varchar(10))");
        if(qry->exec())
        {
            qry->prepare("CREATE UNIQUE INDEX IF NOT EXISTS Name ON Track (name);");
            if(qry->exec())
            {
                qry->prepare("CREATE UNIQUE INDEX IF NOT EXISTS Address ON Track (address);");
                if(qry->exec())
                    {
                        qry->prepare("CREATE UNIQUE INDEX IF NOT EXISTS Phone ON Track (phone);");
                        if(qry->exec())
                            qDebug()<<("Successfully added Unique Indexes.");
                        else
                            qDebug()<<qry->lastError();
                    }
            }
                else
                    qDebug()<<qry->lastError();
        }
        else
            qDebug()<<qry->lastError();

        qry->prepare("CREATE TABLE IF NOT EXISTS RaceType"
                   "(type varchar(25) NOT NULL)");
        if(qry->exec())
        {
            qry->prepare("CREATE UNIQUE INDEX IF NOT EXISTS Type ON RaceType (type);");
            if(qry->exec())
                qDebug()<<("Successfully added Unique Index to RaceType");
            else
                qDebug()<<qry->lastError();
        }
        else{
            qDebug()<<qry->lastError();
        }

        qry->prepare("CREATE TABLE RaceDate (Date VARCHAR NOT NULL )");
        if(qry->exec())
        {
                qDebug()<<("Successfully created RaceDate");
        }
        else{
            qDebug()<<qry->lastError();
        }


    }


    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        db.setDatabaseName(dPath);
        if(!db.open())
        {
            qDebug() << ("Database not open.");
            return false;
        }
        else{
            qDebug() << ("Connected...");
            return true;
        }

    }




public:
    Ui::MainWindow *ui;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

//    void on_pushButton_2_clicked();

    void on_exitButton_clicked();

    void on_addcarButton_clicked();

    void on_addtrackButton_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionDocumentation_triggered();

    void on_addraceButton_clicked();

    void on_actionNew_triggered();

//    void on_tabWidget_tabBarClicked(int index);

    void on_actionCheck_for_Update_triggered();

    void on_actionUser_Defined_Entries_triggered();

    void on_actionPrevious_Information_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    QSqlQueryModel * modal= nullptr;
    QSqlQueryModel * carModal= nullptr;
    QSqlQueryModel * racetypeModal= nullptr;

//    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
