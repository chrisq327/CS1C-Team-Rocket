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
    int id;
protected:
    QPoint topL; //start point
public:
    virtual void draw() = 0;
    virtual void move() = 0;

    virtual ~Shape();

    Shape();
};


#endif // SHAPE_H
