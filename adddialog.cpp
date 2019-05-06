#include "adddialog.h"
#include "properties.h"
#include "parser.h"
#include "admindialog.h"
#include "ui_adddialog.h"
#include "mainwindow.h"

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

    ui->comboBox_penColor->addItem("white");
    ui->comboBox_penColor->addItem("black");
    ui->comboBox_penColor->addItem("red");
    ui->comboBox_penColor->addItem("green");
    ui->comboBox_penColor->addItem("blue");
    ui->comboBox_penColor->addItem("cyan");
    ui->comboBox_penColor->addItem("magenta");
    ui->comboBox_penColor->addItem("yellow");
    ui->comboBox_penColor->addItem("gray");

    ui->comboBox_penStyle->addItem("NoPen");
    ui->comboBox_penStyle->addItem("SolidLine");
    ui->comboBox_penStyle->addItem("DashLine");
    ui->comboBox_penStyle->addItem("DotLine");
    ui->comboBox_penStyle->addItem("DashDotLine");
    ui->comboBox_penStyle->addItem("DashDotDotLine");

    ui->comboBox_penCapStyle->addItem("FlatCap");
    ui->comboBox_penCapStyle->addItem("SquareCap");
    ui->comboBox_penCapStyle->addItem("RoundCap");

    ui->comboBox_penJoinStyle->addItem("MiterJoin");
    ui->comboBox_penJoinStyle->addItem("BevelJoin");
    ui->comboBox_penJoinStyle->addItem("RoundJoin");

    ui->comboBox_brushColor->addItem("white");
    ui->comboBox_brushColor->addItem("black");
    ui->comboBox_brushColor->addItem("red");
    ui->comboBox_brushColor->addItem("green");
    ui->comboBox_brushColor->addItem("blue");
    ui->comboBox_brushColor->addItem("cyan");
    ui->comboBox_brushColor->addItem("magenta");
    ui->comboBox_brushColor->addItem("yellow");
    ui->comboBox_brushColor->addItem("gray");

    ui->comboBox_brushStyle->addItem("SolidPattern");
    ui->comboBox_brushStyle->addItem("HorPattern");
    ui->comboBox_brushStyle->addItem("VerPattern");
    ui->comboBox_brushStyle->addItem("NoBrush");

    ui->comboBox_textColor->addItem("white");
    ui->comboBox_textColor->addItem("black");
    ui->comboBox_textColor->addItem("red");
    ui->comboBox_textColor->addItem("green");
    ui->comboBox_textColor->addItem("blue");
    ui->comboBox_textColor->addItem("cyan");
    ui->comboBox_textColor->addItem("magenta");
    ui->comboBox_textColor->addItem("yellow");
    ui->comboBox_textColor->addItem("gray");

    ui->comboBox_textAlignment->addItem("AlignLeft");
    ui->comboBox_textAlignment->addItem("AlignRight");
    ui->comboBox_textAlignment->addItem("AlignTop");
    ui->comboBox_textAlignment->addItem("AlignBottom");
    ui->comboBox_textAlignment->addItem("AlignCenter");

    ui->comboBox_textFontFamily->addItem("Comic Sans Ms");
    ui->comboBox_textFontFamily->addItem("Courier");
    ui->comboBox_textFontFamily->addItem("Helvetica");
    ui->comboBox_textFontFamily->addItem("Times New Roman");

    ui->comboBox_textFontStyle->addItem("StyleNormal");
    ui->comboBox_textFontStyle->addItem("StyleItalic");
    ui->comboBox_textFontStyle->addItem("StyleOblique");

    ui->comboBox_textFontWeight->addItem("Thin");
    ui->comboBox_textFontWeight->addItem("Light");
    ui->comboBox_textFontWeight->addItem("Normal");
    ui->comboBox_textFontWeight->addItem("Bold");

    for(signed int i = -1; i < 51; i++)
    {
        ui->comboBox_textPointSize->addItem(QString::number(i));
    }

    for(int i = 0; i < 21; i++)
    {
        ui->comboBox_penWidth->addItem(QString::number(i));
    }
}


AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_addShape_clicked()
{
    QString shapeType;

    QString shape = ui->comboBox_shapeType->currentText();


    if(shape == "Line")
    {
        borderProperties bProp;

        QString shape = ui->comboBox_shapeType->currentText();
        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        int index1 = dimensions.indexOf(' ');
        int index2 = dimensions.indexOf(' ', index1);

        QString d1 = dimensions.remove(index1, index2);
        index1 = dimensions.indexOf(' ', index2);
        index2 = dimensions.indexOf(' ', index1);
        QString d2 = dimensions.remove(index1, index2);
        index1 = dimensions.indexOf(' ', index2);
        index2 = dimensions.indexOf(' ', index1);
        QString d3 = dimensions.remove(index1, index2);
        index1 = dimensions.indexOf(' ', index2);
        index2 = dimensions.indexOf(' ', index1);
        QString d4 = dimensions.remove(index1, index2);

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());



        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());
        int id = 10;
        Shape *newLine = new Line(p1, p2, id, bProp);
        adminFunc::addShape(newLine);
    }
    else if(shape == "Polyline")
    {

    }
    else if(shape == "Polygon")
    {

    }
    else if(shape == "Rectangle")
    {

    }
    else if(shape == "Square")
    {

    }
    else if(shape == "Ellipse")
    {

    }
    else if(shape == "Circle")
    {

    }
    else if(shape == "Text")
    {

    }
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
    //hide();

}
