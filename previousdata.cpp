#include "previousdata.h"
#include "ui_previousdata.h"

PreviousData::PreviousData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviousData)
{
    ui->setupUi(this);

}

PreviousData::~PreviousData()
{
    delete ui;
}
