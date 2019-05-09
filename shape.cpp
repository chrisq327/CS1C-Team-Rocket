#include "shape.h"

/* constructors */

/**
 * @brief Shape::Shape constructs a shape
 * @param pos the top left QPoint of the shape
 * @param ID the shape's ID
 */
Shape::Shape(const QPoint& pos, unsigned int ID) : topL{pos}, id{ID}
{
}

/* destructor */

Shape::~Shape()
{
}

/* getters */

/**
 * @brief Shape::getPosition returns the top left QPoint of the shape
 * @return topL
 */
QPoint Shape::getPosition() const
{
    return topL;
}

/**
 * @brief Shape::getId returns the shape's ID
 * @return ID
 */
unsigned int Shape::getId() const
{
    return id;
}

/* setters */

/**
 * @brief Shape::setPosition sets the top left QPoint of the shape
 * @param point the QPoint to be set
 */
void Shape::setPosition(const QPoint& point)
{
    topL = point;
}
