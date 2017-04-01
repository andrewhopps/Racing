#include "previousdata.h"
#include "ui_previousdata.h"

PreviousData::PreviousData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviousData)
{
    ui->setupUi(this);

    ui->bestTimeBox->setInputMask("99:99:999");
    ui->bestTimeBox->setAlignment(Qt::AlignCenter);
    ui->bestTimeBox->setText("0025107");

    ui->avgTimeBox->setInputMask("99:99:999");
    ui->avgTimeBox->setAlignment(Qt::AlignCenter);
    ui->avgTimeBox->setText("0026508");

}

PreviousData::~PreviousData()
{
    delete ui;
}

void PreviousData::on_closeButton_clicked()
{
    PreviousData::close();
}

void PreviousData::on_printButton_clicked()
{

}
