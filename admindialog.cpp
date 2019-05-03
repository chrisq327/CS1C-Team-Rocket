#include "admindialog.h"
#include "ui_admindialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <vector.h>

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
}

AdminDialog::~AdminDialog()
{
    delete ui;
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
    QPainter painter(this);
    QPen pen1(Qt::blue);
    pen1.setWidth(0);
    pen1.setStyle(Qt::DashLine);
    pen1.setCapStyle(Qt::RoundCap);
    pen1.setJoinStyle(Qt::RoundJoin);
    QBrush brush1(Qt::red);
    brush1.setStyle(Qt::VerPattern);
    QRect rec(20,200,170,100);
    painter.setPen(pen1);
    painter.setBrush(brush1);
    painter.drawRect(rec);
}
