#include "polygon.h"

Polygon::Polygon(myStd::vector<QPoint>& p, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(p[0], ID, fProps, bProps)
{
    points = p;
}

void Polygon::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
   // qpainter.drawPolygon(); not sure how to implement yet
}

myStd::vector<QPoint> Polygon::getPoints() const
{
    return points;
}

void Polygon::setPoints(const myStd::vector<QPoint> & p)
{
    points = p;
}

void Polygon::addPoint(const QPoint& newPoint)
{
    points.push_back(newPoint);
}
