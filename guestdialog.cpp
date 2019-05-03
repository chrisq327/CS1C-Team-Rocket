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
   // QPainter painter(this);
    //QPen pen1(Qt::blue);
    //pen1.setWidth(0);
    //pen1.setStyle(Qt::DashLine);
    //pen1.setCapStyle(Qt::RoundCap);
    //pen1.setJoinStyle(Qt::RoundJoin);
    //QBrush brush1(Qt::red);
    //brush1.setStyle(Qt::VerPattern);
    //QRect rec(20,200,170,100);
    //painter.setPen(pen1);
    //painter.setBrush(brush1);
    //painter.drawRect(rec);

    //QPainter painter2(this);
    //QPen pen2(Qt::blue);
    //QLine line(20, 90, 100, 20);
    //pen2.setWidth(0);
    //pen2.setStyle(Qt::DashDotLine);
    //pen2.setCapStyle(Qt::FlatCap);
    //pen2.setJoinStyle(Qt::MiterJoin);
    //painter2.setPen(pen2);
    //painter2.drawLine(line);

    borderProperties borderP;
    QPainter painter3(this);
    QPoint p1(20, 90);
    Line l(p1, 100, 20, 1, borderP);
    l.draw(painter3);

    static const QPoint points[4] = {QPoint(460, 90), QPoint(470, 20), QPoint(530, 40), QPoint(540, 80)};
    //QPainter painter4(this);
    //QPen pen4(Qt::green);
    //pen4.setWidth(6);
    //pen4.setStyle(Qt::SolidLine);
    //pen4.setCapStyle(Qt::FlatCap);
    //pen4.setJoinStyle(Qt::MiterJoin);
    //painter4.setPen(pen4);
    //painter4.drawPolyline(points, 4);

    const myStd::vector<QPoint> polVec(4);
    //const myStd::vector<QPoint> *ptrvec = &polVec;
    QPainter painter5(this);
    Polyline pol(polVec, 2, borderP);
    for(int i = 0; i < 4; i++)
    {
        pol.addPoint(points[i]);
    }
    pol.draw(painter5);

    QPainter painter6(this);
    QPoint p2(20, 200);
    fillProperties fProp;
    Rectangle rect(p2, 170, 100, 4, fProp, borderP);
    rect.draw(painter6);
    update();

    QPainter painter7(this);
    QPoint p3(250, 150);
    Rectangle sqr(p3, 200, 200, 5, fProp, borderP);
    sqr.draw(painter7);

    QPainter painter8(this);
    QPoint p4(520, 200);
    Ellipse elip(p4, 170, 100, 6, fProp, borderP);
    elip.draw(painter8);

    QPainter painter9(this);
    QPoint p5(750, 100);
    Ellipse circle(p5, 200, 200, 7, fProp, borderP);
    circle.draw(painter9);

    QPainter painter10(this);
    QPoint p6(250, 425);
    QPoint p7(500, 50);
    textProperties tProp;
    QString str = "Class Project 2 - 2D Graphics Modeler";
    Text txt(p6, p7, 8, str, tProp);
    txt.draw(painter10);
}

