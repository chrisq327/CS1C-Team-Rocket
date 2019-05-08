#include "polygon.h"

/* constructors */

/**
 * @brief Polygon::Polygon constructs a polygon
 * @param p the QPoints of the polygon
 * @param ID the shape's ID
 * @param fProps the properties of the brush that fills the shape
 * @param bProps the properties of the pen that fills the shape
 */
Polygon::Polygon(const std::vector<QPoint>& p, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(p[0], ID, fProps, bProps)
{
    points = p;
}

/* getters */

/**
 * @brief Polygon::getPoints returns the vector of QPoints of the polygon
 * @return points
 */
std::vector<QPoint> Polygon::getPoints() const
{
    return points;
}

/* setters */

/**
 * @brief Polygon::setPoints sets the vector of QPoints of the polygon
 * @param p the vector to be set
 */
void Polygon::setPoints(const std::vector<QPoint> & p)
{
    points = p;
}

/* functions */

/**
 * @brief Polygon::addPoint adds a new QPoint into the vector of QPoints
 * @param newPoint the point to be added
 */
void Polygon::addPoint(const QPoint& newPoint)
{
    points.push_back(newPoint);
}

/**
 * @brief Polygon::draw draws and fills the polygon
 * @param qpainter draws
 */
void Polygon::draw(QPainter& qpainter)
{
    applyProperties(qpainter);

    qpainter.drawPolygon(points.data(), points.size());
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));

}

/**
 * @brief Polygon::moveOffset offsets the shape's topL by a specified value
 * @param offSet the value of the offset
 */
void Polygon::moveOffset(QPoint & offSet)
{
    for(int i = 0; i < points.size(); i++)
    {
        points[i] = (points[i]+offSet);
    }
    setPosition(points[0]);
}

/**
 * @brief Polygon::toString converts the polygon into an std::string
 * @return the polygon as a string
 */
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
