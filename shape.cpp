#include "shape.h"

Shape::Shape(QPoint& pos, unsigned int ID) : topL{pos}, id{ID}
{
}

Shape::~Shape()
{
}

QPoint Shape::getPosition() const
{
    return topL;
}

unsigned int Shape::getId() const
{
    return id;
}

void Shape::setPosition(const QPoint& point)
{
    topL = point;
}
