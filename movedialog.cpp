#include "movedialog.h"
#include "ui_movedialog.h"

MoveDialog::MoveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoveDialog)
{
    ui->setupUi(this);
}

MoveDialog::~MoveDialog()
{
    delete ui;
}

void MoveDialog::on_pushButton_move_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}
