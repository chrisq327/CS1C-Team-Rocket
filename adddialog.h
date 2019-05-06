#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "shape.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();


private slots:
    void on_pushButton_addShape_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
