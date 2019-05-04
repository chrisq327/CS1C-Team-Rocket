#ifndef FILLABLESHAPE_H
#define FILLABLESHAPE_H

#include "shape.h"
#include "properties.h"

class fillableShape : public Shape
{
public:
    fillableShape(const QPoint&, unsigned int, fillProperties, borderProperties);

    fillProperties getFillProperties();
    borderProperties getBorderProperties();

    void setFillProperties(fillProperties);
    void setBorderProperties(borderProperties);
protected:
    fillProperties fillProps;
    borderProperties borderProps;
    virtual void applyProperties(QPainter&) const;
    virtual std::string toStringProps();
};

#endif // FILLABLESHAPE_H
