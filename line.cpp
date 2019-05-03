#include "line.h"

Line::Line(const QPoint& s, const QPoint& e, unsigned int ID, borderProperties bProps) : nonfillableShape (s, ID, bProps)
{
    end = e;
}

Line::Line(int x1, int y1, int x2, int y2, unsigned int ID, borderProperties bProps) : nonfillableShape (QPoint(x1,y1), ID, bProps)
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
