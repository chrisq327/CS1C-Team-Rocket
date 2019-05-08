#include "rectangle.h"

Rectangle::Rectangle(const QPoint& topL, const QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
}

Rectangle::Rectangle(const QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = w;
    height = h;
}

void Rectangle::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawRect(topL.x(), topL.y(), width, height);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
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

void Rectangle::moveOffset(QPoint &offSet)
{
    setPosition(getPosition()+offSet);
}

std::string Rectangle::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType;
    std::string dimensions;

    if (width == height)
    {
        shapeType = "Square";
        dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(width);
    }

    else if (width!= height)
    {
        shapeType = "Rectangle";
        dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(width) + ", " + std::to_string(height);
    }

    return "ShapeId: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
