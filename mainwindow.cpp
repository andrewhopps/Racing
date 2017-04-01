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

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->tabWidget->setCurrentIndex(0);

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
        QPixmap pix(":/Resources/Images/Resources/Images/CircleRed.png");
        ui->status->setPixmap(pix);
        qDebug()<<"Database Not Open.";
        return;
    }



}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{

    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
    }

    foreach(QPlainTextEdit* pte, findChildren<QPlainTextEdit*>()) {
       pte->clear();
    }

    foreach(QComboBox* cb, findChildren<QComboBox*>()) {
       cb->setCurrentIndex(0);
    }

    ui->wreckCheckbox->setChecked(false);


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
