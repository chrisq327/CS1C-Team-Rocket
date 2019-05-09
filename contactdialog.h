#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>

namespace Ui {
class ContactDialog;
}

class ContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactDialog(QWidget *parent = nullptr);
    ~ContactDialog();

private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::ContactDialog *ui;
};

#endif // CONTACTDIALOG_H
