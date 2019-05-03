#include "text.h"

Text::Text(const QPoint& topL, const QPoint& botR, unsigned int ID, QString& message, textProperties tProps) : Shape(topL, ID)
{
    width = botR.x() - topL.x();
    height = botR.y() - topL.y();
    text = message;
    textProps = tProps;
}

void Text::draw(QPainter& qpainter)
{
    applyProperties(qpainter);
    qpainter.drawText(topL.x(), topL.y(), width, height, textProps.textAlignment, text);
}

void Text::applyProperties(QPainter& qpainter)
{
    qpainter.setPen(textProps.textColor);
    QFont font;

    font.setPointSize(textProps.textSize);
    font.setFamily(textProps.textFontFamily);
    font.setStyle(textProps.textFontStyle);

    qpainter.setFont(font);
}

QString Text::getText() const
{
    return text;
}

int Text::getWidth() const
{
    return width;
}

int Text::getHeight() const
{
    return height;
}

textProperties Text::getTextProps() const
{
    return textProps;
}

void Text::setText(QString& newMessage)
{
    text = newMessage;
}

void Text::setWidth(int w)
{
    width = w;
}

void Text::setHeight(int h)
{
    height = h;
}

