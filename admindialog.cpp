#include "admindialog.h"
#include "ui_admindialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <vector.h>
#include "parser.h"


myStd::vector<Shape*> *ourShapes = new myStd::vector<Shape*>;


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
    fileSave(ourShapes);
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


}
namespace adminFunc {

int getLastID()
{
    int vSize = ourShapes->size();
    int lastID = 1+((*ourShapes)[vSize-1]->getId());
    return lastID;
}

void addShape(Shape *newShape)
{
    ourShapes->push_back(newShape);
}

void deleteShape(int id)
{
    for(int i = 0; i < ourShapes->size(); i++ )
    {
        if(id == (*ourShapes)[i]->getId())
        {
            ourShapes->erase(&(*ourShapes)[i]);
        }
    }
}


}
