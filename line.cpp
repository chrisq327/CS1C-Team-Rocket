#include "line.h"

Line::Line(const QPoint& s, const QPoint& e, unsigned int ID, borderProperties bProps) : nonfillableShape (s, ID, bProps)
{
    end = e;
}

Line::Line(const QPoint& topL, int x2, int y2, unsigned int ID, borderProperties bProps) : nonfillableShape (topL, ID, bProps)
{
    end = QPoint(x2, y2);
}

void Line::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawLine(topL, end);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

QPoint Line::getStart()
{
    return topL;
}

QPoint Line::getEnd()
{
    return end;
}

void Line::setStart(const QPoint& s)
{
    topL = s;
}

void Line::setEnd(const QPoint & e)
{
    end = e;
}

void Line::moveOffset(QPoint & offSet)
{
    setPosition(getStart()+offSet);
    end = end+offSet;
}

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
