#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include "properties.h"

class Text : public Shape
{
public:
    Text(QPoint&, int, int, QString&, textProperties);

    void draw() override;

    QString getText() const;
    int getWidth() const;
    int getHeight() const;
    textProperties getTextProps() const;
private:
    int width;
    int height;
    QString text;
    textProperties textProps;
};

#endif // TEXT_H
