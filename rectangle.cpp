#include "rectangle.h"

Rectangle::Rectangle(QPoint& topL, QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - botR.y();
}

Rectangle::Rectangle(QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = w;
    height = h;
}

void Rectangle::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawRect(topL.x(), topL.y(), width, height);
}

int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setWidth(int w)
{
    width = w;
}

void Rectangle::setHeight(int h)
{
    height = h;
}
