#include "guestdialog.h"
#include "ui_guestdialog.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "properties.h"
#include "nonfillableshape.h"
#include "polyline.h"

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

    //QPainter painter2(this);
    //QPen pen2(Qt::blue);
    //QLine line(20, 90, 100, 20);
    //pen2.setWidth(0);
    //pen2.setStyle(Qt::DashDotLine);
    //pen2.setCapStyle(Qt::FlatCap);
    //pen2.setJoinStyle(Qt::MiterJoin);
    //painter2.setPen(pen2);
    //painter2.drawLine(line);

    //borderProperties borderP;
    //QPainter painter3(this);
    //Line l(20, 90, 100, 20, 1, borderP);
    //l.draw(painter3);

    static const QPoint points[4] = {QPoint(460, 90), QPoint(470, 20), QPoint(530, 40), QPoint(540, 80)};
    //QPainter painter4(this);
    //QPen pen4(Qt::green);
    //pen4.setWidth(6);
    //pen4.setStyle(Qt::SolidLine);
    //pen4.setCapStyle(Qt::FlatCap);
    //pen4.setJoinStyle(Qt::MiterJoin);
    //painter4.setPen(pen4);
    //painter4.drawPolyline(points, 4);

    //const myStd::vector<QPoint> polVec(4);
    //const myStd::vector<QPoint> *ptrvec = &polVec;
    //QPainter painter5(this);
    //Polyline pol(polVec, 2, borderP);
    //for(int i = 0; i < 4; i++)
    //{
       // pol.addPoint(points[i]);
    //}
    //pol.draw(painter5);
}

