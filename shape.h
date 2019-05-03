#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtGui>
#include <QtCore>
#include <QRect>

class Shape
{
private:
    enum ShapeType{line, polyline, polygon, rectangle, square, ellipse, circle, text};
    unsigned int id;
protected:
    QPoint topL; //start point
public:
    virtual void draw(QPainter&) = 0;

    virtual ~Shape();

    Shape(QPoint&, unsigned int);

    QPoint getPosition() const;
    unsigned int getId() const;

    void setPosition(const QPoint&);
};


#endif // SHAPE_H
