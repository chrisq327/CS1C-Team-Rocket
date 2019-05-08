#include "deletedialog.h"
#include "ui_deletedialog.h"
#include "admindialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_pushButton_delete_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    QString delID = ui->lineEdit_shapeId->text();
    adminFunc::deleteShape(delID.toInt());
    parent->show();
    parent->update();
}
