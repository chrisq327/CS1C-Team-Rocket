#include "adddialog.h"
#include "properties.h"
#include "parser.h"
#include "admindialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    ui->comboBox_shapeType->addItem("Line");
    ui->comboBox_shapeType->addItem("Polyline");
    ui->comboBox_shapeType->addItem("Polygon");
    ui->comboBox_shapeType->addItem("Rectangle");
    ui->comboBox_shapeType->addItem("Square");
    ui->comboBox_shapeType->addItem("Ellipse");
    ui->comboBox_shapeType->addItem("Circle");
    ui->comboBox_shapeType->addItem("Text");
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_addShape_clicked()
{
    QString shapeType;

    hide();
}
