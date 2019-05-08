#include "text.h"

/* constructors */

/**
 * @brief Text::Text constructs a text
 * @param topL the top left QPoint of the text
 * @param w the width of the text
 * @param h the height of the text
 * @param ID the shape's ID
 * @param message the text's string
 * @param tProps the properties of the text
 */
Text::Text(const QPoint& topL, int w, int h, unsigned int ID, QString& message, textProperties tProps) : Shape(topL, ID)
{
    width = w;
    height = h;
    if(height < 0)
    {
        height = (height*(-1));
    }
    text = message;
    textProps = tProps;
}

/* getters */

/**
 * @brief Text::getText returns the text's string
 * @return text
 */
QString Text::getText() const
{
    return text;
}

/**
 * @brief Text::getWidth returns the text's width
 * @return width
 */
int Text::getWidth() const
{
    return width;
}

/**
 * @brief Text::getHeight returns the text's height
 * @return height
 */
int Text::getHeight() const
{
    return height;
}

/**
 * @brief Text::getTextProps returns the text's properties
 * @return textProps
 */
textProperties Text::getTextProps() const
{
    return textProps;
}

/* setters */

/**
 * *@brief Text::setText sets the string of the text to a new string
 * @param newMessage the string to be set
 */
void Text::setText(QString& newMessage)
{
    text = newMessage;
}

/**
 * @brief Text::setWidth sets the width of the text to a new value
 * @param w the width to be set
 */
void Text::setWidth(int w)
{
    width = w;
}

/**
 * @brief Text::setHeight sets the height of the text to a new value
 * @param h the height to be set
 */
void Text::setHeight(int h)
{
    height = h;
}

/* functions */

/**
 * @brief Text::draw renders the text
 * @param qpainter renders
 */
void Text::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawText(topL.x(), topL.y(), text);
    qpainter.drawText((topL.x()-10), (topL.y()-10),QString::number(getId()));
}

/**
 * @brief Text::applyProperties applies the text properties to the qpainter
 * @param qpainter renders
 */
void Text::applyProperties(QPainter& qpainter)
{
    qpainter.setPen(textProps.textColor);
    QFont font;

    font.setPointSize(textProps.textSize);
    font.setFamily(textProps.textFontFamily);
    font.setStyle(textProps.textFontStyle);

    qpainter.setFont(font);
}

/**
 * @brief Text::moveOffset offsets the shape's topL by a specified value
 * @param offSet the value of the offset
 */
void Text::moveOffset(QPoint &offSet)
{
    setPosition(getPosition()+offSet);
}

/**
 * @brief Text::toString converts the text into an std::string
 * @return the text as a string
 */
std::string Text::toString()
{
    std::string shapeID = std::to_string(getId());
    std::string shapeType = "Text";
    std::string dimensions = std::to_string(topL.x()) + ", " + std::to_string(topL.y()) + ", " + std::to_string(width) + ", " + std::to_string(height);
    std::string textString = text.toStdString();
    std::string textColor;
    std::string textAlignment;
    std::string textPointSize = std::to_string(textProps.textSize);
    std::string textFontFamily = textProps.textFontFamily.toStdString();
    std::string textFontStyle;
    std::string textFontWeight;

    switch(textProps.textColor)
        {
        case Qt::GlobalColor::white:
            textColor = "white";
            break;
        case Qt::GlobalColor::black:
            textColor = "black";
            break;
        case Qt::GlobalColor::red:
            textColor = "red";
            break;
        case Qt::GlobalColor::green:
            textColor = "green";
            break;
        case Qt::GlobalColor::blue:
            textColor = "blue";
            break;
        case Qt::GlobalColor::cyan:
            textColor = "cyan";
            break;
        case Qt::GlobalColor::magenta:
            textColor = "magenta";
            break;
        case Qt::GlobalColor::yellow:
            textColor = "yellow";
            break;
        case Qt::GlobalColor::gray:
            textColor = "gray";
            break;
        default:
            break;
        }

        switch(textProps.textAlignment)
        {
        case Qt::AlignmentFlag::AlignLeft:
            textAlignment = "AlignLeft";
            break;
        case Qt::AlignmentFlag::AlignRight:
            textAlignment = "AlignRight";
            break;
        case Qt::AlignmentFlag::AlignTop:
            textAlignment = "AlignTop";
            break;
        case Qt::AlignmentFlag::AlignBottom:
            textAlignment = "AlignBottom";
            break;
        case Qt::AlignmentFlag::AlignCenter:
            textAlignment = "AlignCenter";
            break;
        default:
            break;
        }

        switch(textProps.textFontStyle)
        {
        case QFont::Style::StyleNormal:
            textFontStyle = "StyleNormal";
            break;
        case QFont::Style::StyleItalic:
            textFontStyle = "StyleItalic";
            break;
        case QFont::Style::StyleOblique:
            textFontStyle = "StyleOblique";
            break;
        }

        switch(textProps.textFontWeight)
        {
        case QFont::Weight::Thin:
            textFontWeight = "Thin";
            break;
        case QFont::Weight::Light:
            textFontWeight = "Light";
            break;
        case QFont::Weight::Normal:
            textFontWeight = "Normal";
            break;
        case QFont::Weight::Bold:
            textFontWeight = "Bold";
            break;
        default:
            break;
        }

        return "ShapeId: "        + shapeID        + "\n" +
               "ShapeType: "       + shapeType      + "\n" +
               "ShapeDimensions: " + dimensions     + "\n" +
               "TextString: "      + textString     + "\n" +
               "TextColor: "       + textColor      + "\n" +
               "TextAlignment: "   + textAlignment  + "\n" +
               "TextPointSize: "   + textPointSize  + "\n" +
               "TextFontFamily: "  + textFontFamily + "\n" +
               "TextFontStyle: "   + textFontStyle  + "\n" +
               "TextFontWeight: "  + textFontWeight + "\n";
}
