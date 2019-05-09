#include "movedialog.h"
#include "ui_movedialog.h"
#include "admindialog.h"

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
    QString id = ui->lineEdit_shapeId->text();

    QString points = ui->lineEdit_coordinates->text();

    QStringList dimPoints = points.split(" ");

    QString d1 = dimPoints[0];
    QString d2 = dimPoints[1];

   adminFunc::moveShape(id.toInt(), d1.toInt(), d2.toInt());


    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
    parent->update();
}
