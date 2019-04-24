#include "guestdialog.h"
#include "ui_guestdialog.h"
#include "mainwindow.h"
#include <QMessageBox>

GuestDialog::GuestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestDialog)
{
    ui->setupUi(this);
}

GuestDialog::~GuestDialog()
{
    delete ui;
}

void GuestDialog::on_pushButton_Logout_clicked()
{
        QMessageBox::information(this, "Logout", "Guest has logged out");
        MainWindow w;
        w.show();
}
