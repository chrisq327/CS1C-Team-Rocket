#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include "properties.h"

class Text : public Shape
{
public:
    Text(const QPoint&, const QPoint&, unsigned int, QString&, textProperties);

    void draw(QPainter&) override;
    std::string toString() override;

    QString getText() const;
    int getWidth() const;
    int getHeight() const;
    textProperties getTextProps() const;
    void applyProperties(QPainter&);

    void setText(QString&);
    void setWidth(int);
    void setHeight(int);
private:
    int width;
    int height;
    QString text;
    textProperties textProps;
};

#endif // TEXT_H
