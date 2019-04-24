#ifndef GUESTDIALOG_H
#define GUESTDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class GuestDialog;
}

class GuestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuestDialog(QWidget *parent = nullptr);
    ~GuestDialog();

private slots:
    void on_pushButton_Logout_clicked();

private:
    Ui::GuestDialog *ui;
};

#endif // GUESTDIALOG_H

