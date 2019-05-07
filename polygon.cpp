#include "polygon.h"

Polygon::Polygon(const std::vector<QPoint>& p, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(p[0], ID, fProps, bProps)
{
    points = p;
}

void Polygon::draw(QPainter& qpainter)
{
    applyProperties(qpainter);

    qpainter.drawPolygon(points.data(), points.size());
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));

}

std::vector<QPoint> Polygon::getPoints() const
{
    return points;
}

void Polygon::setPoints(const std::vector<QPoint> & p)
{
    points = p;
}

void Polygon::addPoint(const QPoint& newPoint)
{
    points.push_back(newPoint);
}

std::string Polygon::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType = "Polygon";
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
