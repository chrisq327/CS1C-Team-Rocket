#include "admindialog.h"
#include "ui_admindialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <vector.h>
#include "parser.h"


vector<Shape*> *ourShapes = new vector<Shape*>;

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    parser(ourShapes);
    update();
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_pushButton_addShape_clicked()
{
    //this->hide();
    addDialog = new AddDialog(this);
    addDialog->show();
    hide();
}

void AdminDialog::on_pushButton_deleteShape_clicked()
{
    deleteDialog = new DeleteDialog(this);
    deleteDialog->show();
    hide();
}

void AdminDialog::on_pushButton_clicked()
{
    moveDialog = new MoveDialog(this);
    moveDialog->show();
    hide();
}


void AdminDialog::on_pushButton_Logout_clicked()
{
    QMessageBox::information(this, "Logout", "Admin has logged out");
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void AdminDialog::paintEvent(QPaintEvent *event)
{
    Shape *drawThis;
    QPainter painter(this);
    for(int i = 0; i < ourShapes->size(); i++)
    {
        drawThis = (*ourShapes)[i];
        drawThis->draw(painter);
    }

    fileSave(ourShapes);
}
namespace adminFunc {
    void addShape(Shape *newShape)
    {
        ourShapes->push_back(newShape);
    }
}
