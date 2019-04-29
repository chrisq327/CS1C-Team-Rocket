#ifndef FILLABLESHAPE_H
#define FILLABLESHAPE_H

#include "shape.h"
#include "properties.h"

class fillableShape : public Shape
{
public:
    fillableShape(QPoint, fillProperties, borderProperties);

    fillProperties getFillProperties();

    void setFillProperties(fillProperties);
private:
    fillProperties fillProps;
    borderProperties borderProps;
};

#endif // FILLABLESHAPE_H
