#ifndef NONFILLABLESHAPE_H
#define NONFILLABLESHAPE_H

#include "shape.h"
#include "properties.h"

class nonfillableShape : public Shape
{
public:
    nonfillableShape(const QPoint&, unsigned int, borderProperties);

    borderProperties getBorderProperties() const;

    void setBorderProperties(borderProperties);
protected:
    borderProperties borderProps;
    fillProperties fillProps;
    virtual void applyProperties(QPainter&) const;
    virtual std::string toStringProps();
};

#endif // NONFILLABLESHAPE_H
