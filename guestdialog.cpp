#include "guestdialog.h"
#include "ui_guestdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "properties.h"
#include "nonfillableshape.h"
#include "polyline.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"
#include "parser.h"

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
        this->close();
        QWidget *parent = this->parentWidget();
        parent->show();
        //MainWindow w;
        //w.show();
}

void GuestDialog::paintEvent(QPaintEvent *)
{

    myStd::vector<Shape*> *ourShapes = new myStd::vector<Shape*>;
    parser(ourShapes);
    Shape *drawThis;
    QPainter painter(this);
    for(int i = 0; i < ourShapes->size(); i++)
    {
        drawThis = (*ourShapes)[i];
        drawThis->draw(painter);
    }

    fileSave(ourShapes);

}

