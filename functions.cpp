#include "functions.h"
#include "parser.h"

void addShape(vector<Shape*> *ourShapes)
{
    int id;
    int d1, d2, d3, d4, d5, d6, d7, d8;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    string textString;
    string textColor;
    string textAlign;
    int textSize;
    string textFontFamily;
    string textFontStyle;
    string textFontWeight;

    string shapeType;
    string trash;

    int enumPos;

    enumPos = convert(shapeType);

    if(enumPos == 0)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        QPoint p1(d1, d2);
        QPoint p2(d3, d4);


        Shape *newLine = new Line(p1, p2, id, bProp);
        ourShapes->push_back(newLine);
    }
    else if(enumPos == 1)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        QPoint p1(d1, d2);
        QPoint p2(d3, d4);
        QPoint p3(d5, d6);
        QPoint p4(d7, d8);

        std::vector<QPoint> *polylinePoints = new std::vector<QPoint>;
        polylinePoints->push_back(p1);
        polylinePoints->push_back(p2);
        polylinePoints->push_back(p3);
        polylinePoints->push_back(p4);

        Shape *newPolyline = new Polyline(*polylinePoints, id, bProp);
        ourShapes->push_back(newPolyline);
    }
    else if(enumPos == 2)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        fillProperties fProp;

        setBrushColor(fProp, brushColor);
        setBrushStyle(fProp, brushStyle);

        QPoint p1(d1, d2);
        QPoint p2(d3, d4);
        QPoint p3(d5, d6);
        QPoint p4(d7, d8);

        std::vector<QPoint> *polygonPoints = new std::vector<QPoint>;
        polygonPoints->push_back(p1);
        polygonPoints->push_back(p2);
        polygonPoints->push_back(p3);
        polygonPoints->push_back(p4);

        Shape *newPolygon = new Polygon(*polygonPoints, id, fProp, bProp);
        ourShapes->push_back(newPolygon);
    }
    else if(enumPos == 3 )
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        fillProperties fProp;

        setBrushColor(fProp, brushColor);
        setBrushStyle(fProp, brushStyle);

        QPoint p1(d1, d2);
        QPoint p2(d3, d4);

        Shape *newRectangle = new Rectangle(p1, p2, id, fProp, bProp);
        ourShapes->push_back(newRectangle);
    }
    else if(enumPos == 4)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        fillProperties fProp;

        setBrushColor(fProp, brushColor);
        setBrushStyle(fProp, brushStyle);

        QPoint p1(d1, d2);

        Shape *newSquare = new Rectangle(p1, d3, d3, id, fProp, bProp);
        ourShapes->push_back(newSquare);
    }
    else if(enumPos == 5)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        fillProperties fProp;

        setBrushColor(fProp, brushColor);
        setBrushStyle(fProp, brushStyle);

        QPoint p1(d1, d2);
        QPoint p2(d3, d4);

        Shape *newEllipse = new Ellipse(p1, p2, id, fProp, bProp);
        ourShapes->push_back(newEllipse);
    }
    else if (enumPos == 6)
    {
        borderProperties bProp;

        setPenColor(bProp, penColor);
        bProp.penWidth = penWidth;
        setPenStyle(bProp, penStyle);
        setPenCapStyle(bProp, penCapStyle);
        setPenJoinStlye(bProp, penJoinStyle);

        fillProperties fProp;

        setBrushColor(fProp, brushColor);
        setBrushStyle(fProp, brushStyle);

        QPoint p1(d1, d2);

        Shape *newCircle = new Ellipse(p1, d3, d3, id, fProp, bProp);
        ourShapes->push_back(newCircle);
    }
    else if(enumPos == 7)
    {
        textProperties tProp;

        setTextColor(tProp, textColor);
        setTextAlignment(tProp, textAlign);
        tProp.textSize = textSize;
        tProp.textFontFamily = QString::fromStdString(textFontFamily);
        setTextStyle(tProp, textFontStyle);
        setTextWeight(tProp, textFontWeight);

        QString qTextString = QString::fromStdString(textString);
        QPoint p1(d1, d2);
        QPoint p2(d3, d4);
        Shape *newText = new Text(p1, p2, id, qTextString, tProp);
        ourShapes->push_back(newText);
    }
}

void removeShape(vector<Shape*> &ourShapes)
{
    //get ID of shape to be removed
    int ID = 0;

    for (int i=0; i<ourShapes.size(); i++)
    {
        if (ourShapes[i]->getId() == ID)
        {
            delete ourShapes[i];
            ourShapes[i] = nullptr;
        }
    }

}

void moveShape(vector<Shape*> &ourShapes)
{
    //get id of shape to be moved
    int ID = 0;

    //get new coordinates
    QPoint newTopL;


    for (int i=0; i<ourShapes.size(); i++)
    {
        if (ourShapes[i]->getId() == ID)
        {
            ourShapes[i]->setPosition(newTopL);
        }
    }
}
