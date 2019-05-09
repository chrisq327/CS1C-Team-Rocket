#include "rectangle.h"

/* constructors */

/**
 * @brief Rectangle::Rectangle constructs a rectangle
 * @param topL the rectangle's top left QPoint
 * @param botR the rectangle's bottom right QPoint
 * @param ID the shape's ID
 * @param fProps the properties of the brush that fills the shape
 * @param bProps the properties of the pen that draws the shape
 */
Rectangle::Rectangle(const QPoint& topL, const QPoint& botR, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
}

/**
 * @brief Rectangle::Rectangle alternate constructor
 * @param topL the rectangle's top left QPoint
 * @param w the width of the rectagle
 * @param h the height of the rectangle
 * @param ID the shape's ID
 * @param fProps the properties of the brush that fills the shape
 * @param bProps bProps the properties of the pen that draws the shape
 */
Rectangle::Rectangle(const QPoint& topL, int w, int h, unsigned int ID, fillProperties fProps, borderProperties bProps) : fillableShape (topL, ID, fProps, bProps)
{
    width = w;
    height = h;
}

/* getters */

/**
 * @brief Rectangle::getWidth returns the width of the rectangle
 * @return width
 */
int Rectangle::getWidth() const
{
    return width;
}

/**
 * @brief Rectangle::getHeight returns the height of the rectangle
 * @return height
 */
int Rectangle::getHeight() const
{
    return height;
}

/* setters */

/**
 * @brief Rectangle::setWidth sets the width of the rectangle to a new value
 * @param w the width to be set
 */
void Rectangle::setWidth(int w)
{
    width = w;
}

/**
 * @brief Rectangle::setHeight sets the height of the rectangle to a new value
 * @param h the height to be set
 */
void Rectangle::setHeight(int h)
{
    height = h;
}

/* functions */

/**
 * @brief Rectangle::draw draws and fills the rectangle
 * @param qpainter draws and fills
 */
void Rectangle::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawRect(topL.x(), topL.y(), width, height);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

/**
 * @brief Rectangle::moveOffset offsets the shape's topL by a specified value
 * @param offSet the value of the offset
 */
void Rectangle::moveOffset(QPoint &offSet)
{
    setPosition(getPosition()+offSet);
}

/**
 * @brief Rectangle::toString converts the rectangle into an std::string
 * @return the rectangle as a string
 */
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
