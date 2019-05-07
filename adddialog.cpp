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

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());



        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());

        int id = adminFunc::getLastID();

        Shape *newLine = new Line(p1, p2, id, bProp);
        adminFunc::addShape(newLine);
    }
    else if(shape == "Polyline")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];
        QString d5 = dimPoints[4];
        QString d6 = dimPoints[5];
        QString d7 = dimPoints[6];
        QString d8 = dimPoints[7];

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());
        QPoint p3(d5.toInt(), d6.toInt());
        QPoint p4(d7.toInt(), d8.toInt());

        std::vector<QPoint> *polylinePoints = new std::vector<QPoint>;
        polylinePoints->push_back(p1);
        polylinePoints->push_back(p2);
        polylinePoints->push_back(p3);
        polylinePoints->push_back(p4);

        int id = adminFunc::getLastID();

        Shape *newPolyline = new Polyline(*polylinePoints, id, bProp);
        adminFunc::addShape(newPolyline);
    }
    else if(shape == "Polygon")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        fillProperties fProp;

        QString brushColor = ui->comboBox_brushColor->currentText();
        QString brushStyle = ui->comboBox_brushStyle->currentText();

        setBrushColor(fProp, brushColor.toStdString());
        setBrushStyle(fProp, brushStyle.toStdString());

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];
        QString d5 = dimPoints[4];
        QString d6 = dimPoints[5];
        QString d7 = dimPoints[6];
        QString d8 = dimPoints[7];

        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());
        QPoint p3(d5.toInt(), d6.toInt());
        QPoint p4(d7.toInt(), d8.toInt());

        std::vector<QPoint> *polygonPoints = new std::vector<QPoint>;
        polygonPoints->push_back(p1);
        polygonPoints->push_back(p2);
        polygonPoints->push_back(p3);
        polygonPoints->push_back(p4);

        int id = adminFunc::getLastID();

        Shape *newPolygon = new Polygon(*polygonPoints, id, fProp, bProp);
        adminFunc::addShape(newPolygon);
    }
    else if(shape == "Rectangle")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        fillProperties fProp;

        QString brushColor = ui->comboBox_brushColor->currentText();
        QString brushStyle = ui->comboBox_brushStyle->currentText();

        setBrushColor(fProp, brushColor.toStdString());
        setBrushStyle(fProp, brushStyle.toStdString());

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];

        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());

        int id = adminFunc::getLastID();

        Shape *newRectangle = new Rectangle(p1, p2, id, fProp, bProp);
        adminFunc::addShape(newRectangle);
    }
    else if(shape == "Square")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        fillProperties fProp;

        QString brushColor = ui->comboBox_brushColor->currentText();
        QString brushStyle = ui->comboBox_brushStyle->currentText();

        setBrushColor(fProp, brushColor.toStdString());
        setBrushStyle(fProp, brushStyle.toStdString());

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];

        QPoint p1(d1.toInt(), d2.toInt());


        int id = adminFunc::getLastID();

        Shape *newSquare = new Rectangle(p1, d3.toInt(), d3.toInt(), id, fProp, bProp);
        adminFunc::addShape(newSquare);
    }
    else if(shape == "Ellipse")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        fillProperties fProp;

        QString brushColor = ui->comboBox_brushColor->currentText();
        QString brushStyle = ui->comboBox_brushStyle->currentText();

        setBrushColor(fProp, brushColor.toStdString());
        setBrushStyle(fProp, brushStyle.toStdString());

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];

        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());

        int id = adminFunc::getLastID();

        Shape *newEllipse = new Ellipse(p1, p2, id, fProp, bProp);
        adminFunc::addShape(newEllipse);
    }
    else if(shape == "Circle")
    {
        borderProperties bProp;

        QString penColor = ui->comboBox_penColor->currentText();
        QString penStyle = ui->comboBox_penStyle->currentText();
        QString penCapStyle = ui->comboBox_penCapStyle->currentText();
        QString penJoinStyle = ui->comboBox_penJoinStyle->currentText();
        QString penWidth = ui->comboBox_penWidth->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setPenColor(bProp, penColor.toStdString());
        bProp.penWidth = penWidth.toInt();
        setPenStyle(bProp, penStyle.toStdString());
        setPenCapStyle(bProp, penCapStyle.toStdString());
        setPenJoinStlye(bProp, penJoinStyle.toStdString());

        fillProperties fProp;

        QString brushColor = ui->comboBox_brushColor->currentText();
        QString brushStyle = ui->comboBox_brushStyle->currentText();

        setBrushColor(fProp, brushColor.toStdString());
        setBrushStyle(fProp, brushStyle.toStdString());

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];

        QPoint p1(d1.toInt(), d2.toInt());

        int id = adminFunc::getLastID();

        Shape *newCircle = new Ellipse(p1, d3.toInt(), d3.toInt(), id, fProp, bProp);
        adminFunc::addShape(newCircle);
    }
    else if(shape == "Text")
    {
        textProperties tProp;

        QString textColor = ui->comboBox_textColor->currentText();
        QString textAlign = ui->comboBox_textAlignment->currentText();
        QString textSize = ui->comboBox_textPointSize->currentText();
        QString textFontStyle = ui->comboBox_textFontStyle->currentText();
        QString textFontFamily = ui->comboBox_textFontFamily->currentText();
        QString textFontWeight = ui->comboBox_textFontWeight->currentText();
        QString dimensions = ui->lineEdit_dimensions->text();

        setTextColor(tProp, textColor.toStdString());
        setTextAlignment(tProp, textAlign.toStdString());
        tProp.textSize = textSize.toInt();
        tProp.textFontFamily = textFontFamily;
        setTextStyle(tProp, textFontStyle.toStdString());
        setTextWeight(tProp, textFontWeight.toStdString());


        QString qTextString = ui->lineEdit_textString->text();

        QStringList dimPoints = dimensions.split(" ");

        QString d1 = dimPoints[0];
        QString d2 = dimPoints[1];
        QString d3 = dimPoints[2];
        QString d4 = dimPoints[3];


        QPoint p1(d1.toInt(), d2.toInt());
        QPoint p2(d3.toInt(), d4.toInt());

        int id = adminFunc::getLastID();

        Shape *newText = new Text(p1, p2, id, qTextString, tProp);

        adminFunc::addShape(newText);
    }
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}
