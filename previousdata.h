#ifndef PREVIOUSDATA_H
#define PREVIOUSDATA_H

#include <QDialog>

namespace Ui {
class PreviousData;
}

class PreviousData : public QDialog
{
    Q_OBJECT

public:
    explicit PreviousData(QWidget *parent = 0);
    ~PreviousData();

private slots:
    void on_closeButton_clicked();

    void on_printButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::PreviousData *ui;
};

#endif // PREVIOUSDATA_H
