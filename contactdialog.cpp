#include "contactdialog.h"
#include "ui_contactdialog.h"
#include <QMessageBox>

ContactDialog::ContactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactDialog)
{
    ui->setupUi(this);
}

ContactDialog::~ContactDialog()
{
    delete ui;
}

void ContactDialog::on_pushButton_submit_clicked()
{
    QMessageBox::information(this, "Contact", "Message submitted. Thank you for contacting us!");
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}
