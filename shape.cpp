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

/* operators */

/**
 * @brief Shape::operator == determines if two shapes are the same (id's are identical)
 * @param rhs the other shape being compared to
 * @return true if shapes are the same
 */
bool Shape::operator==(Shape &rhs)
{
    return id == rhs.id;
}

/**
 * @brief Shape::operator != determines if two shapes are not the same (id's are not identical)
 * @param rhs the otehr shape being compared to
 * @return true if shapes are not the same
 */
bool Shape::operator!=(Shape &rhs)
{
    return id != rhs.id;
}
