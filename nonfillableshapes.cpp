#include "nonfillableshape.h"
#include "properties.h"

nonfillableShape::nonfillableShape(const QPoint& pos, unsigned int ID, borderProperties borderProperties) : Shape(pos, ID)
{
    borderProps = borderProperties;
}

borderProperties nonfillableShape::getBorderProperties() const
{
    return borderProps;
}

void nonfillableShape::setBorderProperties(borderProperties props)
{
    borderProps = props;
}

void nonfillableShape::applyProperties(QPainter & qpainter) const
{
    QPen pen;
    pen.setColor(borderProps.penColor);
    pen.setWidth(borderProps.penWidth);
    pen.setStyle(borderProps.penStyle);
    pen.setCapStyle(borderProps.penCapStyle);
    pen.setJoinStyle(borderProps.penJoinStyle);

    qpainter.setPen(pen);
}
