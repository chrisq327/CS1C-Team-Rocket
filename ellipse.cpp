#include "ellipse.h"

Ellipse::Ellipse(QPoint& topL, QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
}

Ellipse::Ellipse(QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = w;
    height = h;
}

int Ellipse::getWidth()
{
    return width;
}

int Ellipse::getHeight()
{
    return height;
}

void Ellipse::setWidth(int w)
{
    width = w;
}

void Ellipse::setHeight(int h)
{
    height = h;
}

void Ellipse::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    QRect box(topL.x(), topL.y(), width, height);
    qpainter.drawEllipse(box);
}
