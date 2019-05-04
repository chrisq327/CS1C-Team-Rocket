#include "polyline.h"

Polyline::Polyline(const myStd::vector<QPoint> &p, unsigned int ID, borderProperties bProps) : nonfillableShape(p[0], ID, bProps)
{
    points = p;
}

void Polyline::draw(QPainter& qpainter)
{
    applyProperties(qpainter);

    QPoint arrayPoints[points.size()];

    for (int i=0; i<points.size(); i++)
    {
        arrayPoints[i] = points[i];
    }

    qpainter.drawPolyline(arrayPoints, points.size());
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

std::string Polyline::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType = "Polygon";
    std::string dimensions;

    for(int i=0; i<points.size(); i++)
    {
        dimensions += std::to_string(points[i].x()) + ", " + std::to_string(points[i].y());
        dimensions += (i != points.size() - 1 ? ", " : "");
    }

    return "Shape Id: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
