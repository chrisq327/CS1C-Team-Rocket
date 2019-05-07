#include "polyline.h"

Polyline::Polyline(const std::vector<QPoint> &p, unsigned int ID, borderProperties bProps) : nonfillableShape(p[0], ID, bProps)
{
    points = p;
}

void Polyline::draw(QPainter& qpainter)
{
    applyProperties(qpainter);

    qpainter.drawPolyline(points.data(), points.size());
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

std::vector<QPoint> Polyline::getPoints() const
{
    return points;
}

void Polyline::setPoints(const std::vector<QPoint> &p)
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
    std::string shapeType = "Polyline";
    std::string dimensions;

    for(int i=0; i<points.size(); i++)
    {
        dimensions += std::to_string(points[i].x()) + ", " + std::to_string(points[i].y());
        dimensions += (i != points.size() - 1 ? ", " : "");
    }

    return "ShapeId: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
