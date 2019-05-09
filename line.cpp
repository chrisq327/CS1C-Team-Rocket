#include "line.h"

/* constructors */

/**
 * @brief Line::Line constructs a line
 * @param s the start QPoint
 * @param e the end QPoint
 * @param ID the shape's ID
 * @param bProps the properties of the pen that draws the line
 */
Line::Line(const QPoint& s, const QPoint& e, unsigned int ID, borderProperties bProps) : nonfillableShape (s, ID, bProps)
{
    end = e;
}

/**
 * @brief Line::Line alternate constructor
 * @param topL the starting QPoint of the line
 * @param x2 the x-coordinate of the end QPoint
 * @param y2 the y-coordinate of the end QPoint
 * @param ID the shape's ID
 * @param bProps the properties of the pen that draws the line
 */
Line::Line(const QPoint& topL, int x2, int y2, unsigned int ID, borderProperties bProps) : nonfillableShape (topL, ID, bProps)
{
    end = QPoint(x2, y2);
}

/* getters */

/**
 * @brief Line::getStart returns the starting QPoint of the line
 * @return start
 */
QPoint Line::getStart()
{
    return topL;
}

/**
 * @brief Line::getEnd returns the end QPoint of the line
 * @return  end
 */
QPoint Line::getEnd()
{
    return end;
}

/* setters */

/**
 * @brief Line::setStart sets the starting QPoint of the line
 * @param s the QPoint to be set
 */
void Line::setStart(const QPoint& s)
{
    topL = s;
}

/**
 * @brief Line::setEnd sets the ending QPoint of the line
 * @param e the QPoint to be set
 */
void Line::setEnd(const QPoint & e)
{
    end = e;
}

/* functions */

/**
 * @brief Line::draw renders the line
 * @param qpainter draws the line
 */
void Line::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawLine(topL, end);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

/**
 * @brief Line::moveOffset offsets the shape's start by a specified value
 * @param offSet the value of the offset
 */
void Line::moveOffset(QPoint & offSet)
{
    setPosition(getStart()+offSet);
    end = end+offSet;
}

/**
 * @brief Line::toString converts the line into an std::string
 * @return the line as a string
 */
std::string Line::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType = "Line";
    std::string dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(end.x()) + ", " + std::to_string(end.y());

    return "ShapeId: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
