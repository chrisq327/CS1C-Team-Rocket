#include "line.h"

Line::Line(QPoint& s, QPoint& e, unsigned int ID, borderProperties bProps) : nonfillableShape (s, ID, bProps)
{
    end = e;
}

Line::Line(QPoint& topL, int x2, int y2, unsigned int ID, borderProperties bProps) : nonfillableShape (topL, ID, bProps)
{
    //start = QPoint(x1, y1); //Added this line(chris)
    end = QPoint(x2, y2);
}

void Line::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawLine(topL, end);
}

QPoint Line::getStart()
{
    return start;
}

QPoint Line::getEnd()
{
    return end;
}

void Line::setStart(const QPoint& s)
{
    start = s;
}

void Line::setEnd(const QPoint & e)
{
    end = e;
}
