#include "ellipse.h"

Ellipse::Ellipse(const QPoint& topL, const QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
}

Ellipse::Ellipse(const QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
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
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

std::string Ellipse::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType;
    std::string dimensions;

    if (width == height)
    {
        shapeType = "Circle";
        dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(width);
    }

    else if (width!= height)
    {
        shapeType = "Ellipse";
        dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(width) + ", " + std::to_string(height);
    }

    return "Shape Id: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
