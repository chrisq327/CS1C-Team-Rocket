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

std::string fillableShape::toStringProps()
{
    std::string penColor;
    std::string penWidth = std::to_string(borderProps.penWidth);
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;

    std::string brushColor;
    std::string brushStyle;

    switch(borderProps.penColor)
        {
        case Qt::GlobalColor::white:
            penColor = "white";
            break;
        case Qt::GlobalColor::black:
            penColor = "black";
            break;
        case Qt::GlobalColor::red:
            penColor = "red";
            break;
        case Qt::GlobalColor::green:
            penColor = "green";
            break;
        case Qt::GlobalColor::blue:
            penColor = "blue";
            break;
        case Qt::GlobalColor::cyan:
            penColor = "cyan";
            break;
        case Qt::GlobalColor::magenta:
            penColor = "magenta";
            break;
        case Qt::GlobalColor::yellow:
            penColor = "yellow";
            break;
        case Qt::GlobalColor::gray:
            penColor = "gray";
            break;
        default: //Gets rid of the warnings
            break;
        }

        switch(borderProps.penStyle)
        {
        case Qt::PenStyle::NoPen:
            penStyle = "NoPen";
            break;
        case Qt::PenStyle::SolidLine:
            penStyle = "SolidLine";
            break;
        case Qt::PenStyle::DashLine:
            penStyle = "DashLine";
            break;
        case Qt::PenStyle::DotLine:
            penStyle = "DotLine";
            break;
        case Qt::PenStyle::DashDotLine:
            penStyle = "DashDotLine";
            break;
        case Qt::PenStyle::DashDotDotLine:
            penStyle = "DashDotDotLine";
            break;
        default: //Gets rid of the warnings
            break;
        }

        switch(borderProps.penCapStyle)
        {
        case Qt::PenCapStyle::FlatCap:
            penCapStyle = "FlatCap";
            break;
        case Qt::PenCapStyle::SquareCap:
            penCapStyle = "SquareCap";
            break;
        case Qt::PenCapStyle::RoundCap:
            penCapStyle = "RoundCap";
            break;
        default:
            break;
        }

        switch(borderProps.penJoinStyle)
        {
        case Qt::PenJoinStyle::MiterJoin:
            penJoinStyle = "MiterJoin";
            break;
        case Qt::PenJoinStyle::BevelJoin:
            penJoinStyle = "BevelJoin";
            break;
        case Qt::PenJoinStyle::RoundJoin:
            penJoinStyle = "RoundJoin";
            break;
        default: //Gets rid of the warnings
            break;
        }

        switch(fillProps.brushColor)
            {
            case Qt::GlobalColor::white:
                brushColor = "white";
                break;
            case Qt::GlobalColor::black:
                brushColor = "black";
                break;
            case Qt::GlobalColor::red:
                brushColor = "red";
                break;
            case Qt::GlobalColor::green:
                brushColor = "green";
                break;
            case Qt::GlobalColor::blue:
                brushColor = "blue";
                break;
            case Qt::GlobalColor::cyan:
                brushColor = "cyan";
                break;
            case Qt::GlobalColor::magenta:
                brushColor = "magenta";
                break;
            case Qt::GlobalColor::yellow:
                brushColor = "yellow";
                break;
            case Qt::GlobalColor::gray:
                brushColor = "gray";
                break;
            default: //Gets rid of the warnings
                break;
            }

            switch(fillProps.brushStyle)
            {
            case Qt::BrushStyle::SolidPattern:
                brushStyle = "SolidPattern";
                break;
            case Qt::BrushStyle::HorPattern:
                brushStyle = "HorPattern";
                break;
            case Qt::BrushStyle::VerPattern:
                brushStyle = "VerPattern";
                break;
            case Qt::BrushStyle::NoBrush:
                brushStyle = "NoBrush";
                break;
            default:
                break;
            }

        return "PenColor: "     + penColor     + "\n" +
               "PenWidth: "     + penWidth     + "\n" +
               "PenStyle: "     + penStyle     + "\n" +
               "PenCapStyle: "  + penCapStyle  + "\n" +
               "PenJoinStyle: " + penJoinStyle + "\n" +
               "BrushColor: "   + brushColor   + "\n" +
               "BrushStyle: "   + brushStyle   + "\n";
}
