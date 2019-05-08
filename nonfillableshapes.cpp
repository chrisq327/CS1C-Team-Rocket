#include "nonfillableshape.h"
#include "properties.h"

/* constructors */

/**
 * @brief nonfillableShape::nonfillableShape constructs a shape that cannot be filled
 * @param pos the top left QPoint of the shape
 * @param ID the shape's ID
 * @param borderProperties the properties of the pen that draws the shape
 */
nonfillableShape::nonfillableShape(const QPoint& pos, unsigned int ID, borderProperties borderProperties) : Shape(pos, ID)
{
    borderProps = borderProperties;
}

/* getters */

/**
 * @brief nonfillableShape::getBorderProperties returns the properties of the pen that draws the shape
 * @return the properties
 */
borderProperties nonfillableShape::getBorderProperties() const
{
    return borderProps;
}

/* setters */

/**
 * @brief nonfillableShape::setBorderProperties sets the properties of the pen that draws the shape
 * @param props the properties to be set
 */
void nonfillableShape::setBorderProperties(borderProperties props)
{
    borderProps = props;
}

/* functions */

/**
 * @brief nonfillableShape::applyProperties applies the properties of the pen to the qpainter
 * @param qpainter has it's pen set
 */
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

/**
 * @brief nonfillableShape::toStringProps converts the properties of the pen into a string
 * @return the string
 */
std::string nonfillableShape::toStringProps()
{
    std::string penColor;
    std::string penWidth = std::to_string(borderProps.penWidth);
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;

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
        default: //Gets rid of the warnings
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

        return "PenColor: "     + penColor     + "\n" +
               "PenWidth: "     + penWidth     + "\n" +
               "PenStyle: "     + penStyle     + "\n" +
               "PenCapStyle: "  + penCapStyle  + "\n" +
               "PenJoinStyle: " + penJoinStyle + "\n";
}
