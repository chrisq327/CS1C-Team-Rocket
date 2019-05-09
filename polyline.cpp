#include "polyline.h"

/* constructors */

/**
 * @brief Polyline::Polyline constructs a polyline
 * @param p the vector of QPoints
 * @param ID the shape's ID
 * @param bProps the properties of the pen that draws the polyline
 */
Polyline::Polyline(const std::vector<QPoint> &p, unsigned int ID, borderProperties bProps) : nonfillableShape(p[0], ID, bProps)
{
    points = p;
}

/* getters */

/**
 * @brief Polyline::getPoints returns the vector of QPoints of the polyline
 * @return points
 */
std::vector<QPoint> Polyline::getPoints() const
{
    return points;
}

/* setters */

/**
 * @brief Polyline::setPoints sets the vector of QPoints of the polyline
 * @param p the vector to be set
 */
void Polyline::setPoints(const std::vector<QPoint> &p)
{
    points = p;
}

/* functions */

/**
 * @brief Polyline::draw draws the polyline
 * @param qpainter draws
 */
void Polyline::draw(QPainter& qpainter)
{
    applyProperties(qpainter);

    qpainter.drawPolyline(points.data(), points.size());
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

/**
 * @brief Polyline::addPoint adds a new QPoint to the vector of QPoints
 * @param newPoint the new point to be added
 */
void Polyline::addPoint(const QPoint & newPoint)
{
    points.push_back(newPoint);
}

/**
 * @brief Polyline::moveOffset offsets the shape's topL by a specified value
 * @param offSet the value of the offset
 */
void Polyline::moveOffset(QPoint & offSet)
{
    for(int i = 0; i < points.size(); i++)
    {
        points[i] = (points[i]+offSet);
    }
    setPosition(points[0]);
}

/**
 * @brief Polyline::toString converts the polyline into an std::string
 * @return the polyline as a string
 */
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
