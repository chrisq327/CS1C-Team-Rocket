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

/* functions */

namespace adminFunc {
/**
 * @brief getLastID returns id of the highest shape
 * @return highest id
 */
int getLastID()
{
    int vSize = ourShapes->size();
    int lastID = 1+((*ourShapes)[vSize-1]->getId());
    return lastID;
}

/**
 * @brief addShape adds a pointer to a shape into the vector of shape pointers
 * @param newShape pointer to new shape to be added to vector
 */
void addShape(Shape *newShape)
{
    ourShapes->push_back(newShape);
}

/**
 * @brief deleteShape deletes the shape with the corresponding ID
 * @param id id of the shape to be deleted
 */
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
/**
 * @brief moveShape moves by offsetting the x and y axis
 * @param id id of the shape to be moved
 * @param d1 amount of change to x axis
 * @param d2 amount of change to the y axis
 */
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
