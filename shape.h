#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtGui>
#include <QtCore>

class Shape
{
private:
    enum ShapeType{line, polyline, polygon, rectangle, square, ellipse, circle, text};
    /*
    enum Color{white, black, red, green, blue, cyan, magenta, yellow, gray};
    enum PenStyle{NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
    enum PenCapStyle{FlatCap, SquareCap, RoundCap};
    */

    int id;
    int penWidth;

 //   Qt::ShapeType       shapeType;
    QPainter            painter;
    QPen                pen;
    QBrush              brush;

    Qt::BrushStyle      brushStyle;
    Qt::GlobalColor     brushColor;
    Qt::GlobalColor     penColor;
    Qt::PenStyle        penStyle;
    Qt::PenCapStyle     penCapStyle;
    Qt::PenJoinStyle    penJointStyle;
 //   Qt::BrushStyle      brushStyle;
public:
    virtual void Draw() = 0;
    virtual void transformShape() = 0;
    Shape();
};

class Line : public Shape
{
private:
QPoint point1;
QPoint point2;
 void Draw() override;
};

class PolyLine : public Shape
{
    // vector of points
};

class Polygon : public Shape
{
    //vector of points
};

class Rectangle : public Shape
{
    QPoint start;
    double length;
    double width;
};

class Square : public Shape
{
    QPoint start;
    double length;
};

class Ellipse : public Shape
{
    QPoint vertex;
    //semi major axis
    //semi minor axis
};

class Circle : public Shape
{
    QPoint vertex;
};

class Text : public Shape
{
    QPoint vertex;
};

#endif // SHAPE_H
