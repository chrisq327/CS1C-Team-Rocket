#include "ellipse.h"

/* constructors */

/**
 * @brief Ellipse::Ellipse constructor
 * @param topL the top left point of the rectangle encompassing the ellipse
 * @param botR the bottom right point of the rectangle encompassing the ellipse
 * @param ID the shape's ID
 * @param fProps properties of the brush
 * @param bProps properties of the pen
 */
Ellipse::Ellipse(const QPoint& topL, const QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape(topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
}

/**
 * @brief Ellipse::Ellipse alternate constructor
 * @param topL the top left point of the rectangle encompassing the ellipse
 * @param w width of the rectangle encompassing the ellipse
 * @param h height of the rectangle encompassing the ellipse
 * @param ID the shape's ID
 * @param fProps properties of the brush
 * @param bProps properties of the pen
 */
Ellipse::Ellipse(const QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = w;
    height = h;
}

/**
 * @brief Ellipse::getWidth returns width
 * @return the width of the rectangle encompassing the ellipse
 */
int Ellipse::getWidth()
{
    return width;
}

/**
 * @brief Ellipse::getHeight returns height
 * @return the height of the rectangle encompassing the ellipse
 */
int Ellipse::getHeight()
{
    return height;
}

/**
 * @brief Ellipse::setWidth sets the width of the rectangle encompassing the ellipse to a new value
 * @param w the width to be set
 */
void Ellipse::setWidth(int w)
{
    width = w;
}

/**
 * @brief Ellipse::setHeight sets the height of the rectangle encompassing the ellipse
 * @param h the height to be set
 */
void Ellipse::setHeight(int h)
{
    height = h;
}

/**
 * @brief Ellipse::moveOffset offsets the shape's topL by a specified value
 * @param offSet the value of the offset
 */
void Ellipse::moveOffset(QPoint& offSet)
{
    setPosition(getPosition()+offSet);
}

/**
 * @brief Ellipse::draw renders the shape
 * @param qpainter draws the shape
 */
void Ellipse::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    QRect box(topL.x(), topL.y(), width, height);
    qpainter.drawEllipse(box);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

/**
 * @brief Ellipse::toString converts the shape into an std::string to be written to the database
 * @return the shape as a string
 */
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

    return "ShapeId: "        + shapeID     + "\r\n" +
           "ShapeType: "       + shapeType   + "\r\n" +
           "ShapeDimensions: " + dimensions  + "\r\n" +
           toStringProps();
}
