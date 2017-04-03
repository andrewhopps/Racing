#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "track.h"
#include "about.h"
#include "documentation.h"
#include "viewtable.h"
#include "racetype.h"
#include "previousdata.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    aPath = qApp->applicationDirPath();
    dPath = aPath + "/RacingInfo.sqlite";


    if(dbExists())
    {
        if(!db.isOpen())
        {
            connOpen();
        }
        updateWindow();

    }
    else{
        qDebug()<<"Database Not Open.";
        return;
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
    MainWindow::close();
}

void MainWindow::on_addcarButton_clicked()
{
    Car car;
    car.setModal(true);
    car.exec();
    updateWindow();

}

void MainWindow::on_addtrackButton_clicked()
{
    Track track;
    track.setModal(true);
    track.exec();
    updateWindow();

}

void MainWindow::on_actionExit_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_actionDocumentation_triggered()
{
    Documentation doc;
    doc.setModal(true);
    doc.exec();
}

void MainWindow::on_addraceButton_clicked()
{
    RaceType rt;
    rt.setModal(true);
    rt.exec();
}

void MainWindow::on_actionNew_triggered()
{

}





/*
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        qDebug()<<"First Tab";
    }
    else if(index == 1)
    {
        qDebug()<<"Second Tab";

        QString inner, middle, outer;
        inner = "green";
        middle = "yellow";
        outer = "red";
        QPen blackpen(Qt::black);
        blackpen.setStyle(Qt::NoPen);
        QLinearGradient gradient(0,0,30,0); // horizontal gradient
        gradient.setColorAt(0, QColor(outer));
        gradient.setColorAt(0.5, QColor(middle));
        gradient.setColorAt(1, QColor(inner));
        rect = scene->addRect(0,0,30,50,blackpen,gradient);

    }
    else
    {
        qDebug()<<"Other Tab";
    }
}
*/

void MainWindow::on_actionCheck_for_Update_triggered()
{

}

void MainWindow::on_actionUser_Defined_Entries_triggered()
{
    ViewTable vt;
    vt.setModal(true);
    vt.exec();
}

void MainWindow::on_actionPrevious_Information_triggered()
{
    PreviousData pd;
    pd.setModal(true);
    pd.exec();
}

void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{
//    QHBoxLayout *hlayout = new QHBoxLayout(ui->frame_2); //sets layout on existing frame
//    QPushButton *newCar = new QPushButton(); //creates new button
//    newCar->setStyleSheet("background-color: rgb(240, 240, 240);"
//                          "background-image: url(:/Resources/Images/Resources/Images/carButton.png);"
//                          "background-repeat: no-repeat;"
//                          "background-attachment: fixed;"
//                          "background-position: center;");
//    newCar->setFixedSize(213, 108); // Sets button size
//    newCar->setIconSize(QSize(200,100)); //Sets icon size
//    hlayout->addWidget(newCar); //places new button into frame

}
