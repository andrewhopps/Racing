#include "documentation.h"
#include "ui_documentation.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Documentation::Documentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Documentation)
{
    ui->setupUi(this);

    QFile file("C:\\Users\\Andrew\\Racing\\Resources\\Documentation.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());

    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());
}

Documentation::~Documentation()
{
    delete ui;
}
