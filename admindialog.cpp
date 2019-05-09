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
    addDialog = new AddDialog(this);
    addDialog->show();
    hide();
}

void AdminDialog::on_pushButton_deleteShape_clicked()
{
    deleteDialog = new DeleteDialog(this);
    deleteDialog->show();
}

void AdminDialog::on_pushButton_moveShape_clicked()
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

/* functions */
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
            delete (*ourShapes)[i];
            ourShapes->erase(&(*ourShapes)[i]);
        }
    }
}
void moveShape(int id, const int d1, const int d2)
{
    for(int i = 0; i < ourShapes->size(); i++ )
    {
        if(id == (*ourShapes)[i]->getId())
        {
                QPoint offSet(d1, d2);
                (*ourShapes)[i]->moveOffset(offSet);
        }
    }
}
}

void AdminDialog::on_pushButton_testimonials_clicked()
{
    hide();
    testimonialsDialog = new TestimonialsDialog(this);
    testimonialsDialog->show();
}
