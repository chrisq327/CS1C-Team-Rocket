#ifndef NONFILLABLESHAPE_H
#define NONFILLABLESHAPE_H

#include "shape.h"
#include "properties.h"

class nonfillableShape : public Shape
{
public:
    nonfillableShape(QPoint, borderProperties);
private:
    borderProperties borderProps;
};

#endif // NONFILLABLESHAPE_H
