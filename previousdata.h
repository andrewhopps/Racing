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

private:
    Ui::PreviousData *ui;
};

#endif // PREVIOUSDATA_H
