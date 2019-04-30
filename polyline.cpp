#include "polyline.h"

Polyline::Polyline(const myStd::vector<QPoint>& p, unsigned int ID, borderProperties bProps) : nonfillableShape(p[0], ID, bProps)
{
    points = p;
}

void Polyline::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
  //qpainter.drawPolyline() idk how to use yet
}

myStd::vector<QPoint> Polyline::getPoints() const
{
    return points;
}

void Polyline::setPoints(const myStd::vector<QPoint> &p)
{
    points = p;
}

void Polyline::addPoint(const QPoint & newPoint)
{
    points.push_back(newPoint);
}
