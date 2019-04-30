#include "fillableshape.h"

fillableShape::fillableShape(const QPoint& pos, unsigned int ID, fillProperties fillProperties, borderProperties borderProperties) : Shape(pos, ID)
{
    fillProps = fillProperties;
    borderProps = borderProperties;
}



fillProperties fillableShape::getFillProperties()
{
    return fillProps;
}

borderProperties fillableShape::getBorderProperties()
{
    return borderProps;
}



void fillableShape::setFillProperties(fillProperties props)
{
    fillProps = props;
}

void fillableShape::setBorderProperties(borderProperties props)
{
    borderProps = props;
}

void fillableShape::applyProperties(QPainter & qpainter) const
{
    QPen pen;
    pen.setColor(borderProps.penColor);
    pen.setWidth(borderProps.penWidth);
    pen.setStyle(borderProps.penStyle);
    pen.setCapStyle(borderProps.penCapStyle);
    pen.setJoinStyle(borderProps.penJoinStyle);

    qpainter.setPen(pen);

    QBrush brush;
    brush.setColor(fillProps.brushColor);
    brush.setStyle(fillProps.brushStyle);

    qpainter.setBrush(brush);
}
